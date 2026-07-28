/**
 * Copyright (c) 2015 - present LibDriver All rights reserved
 * 
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 *
 * @file      driver_pmsx003_interface_template.c
 * @brief     driver pmsx003 interface template source file
 * @version   1.0.0
 * @author    Shifeng Li
 * @date      2025-05-15
 *
 * <h3>history</h3>
 * <table>
 * <tr><th>Date        <th>Version  <th>Author      <th>Description
 * <tr><td>2025/05/15  <td>1.0      <td>Shifeng Li  <td>first upload
 * </table>
 */

#include "driver_pmsx003_interface.h"
#include "main.h"
#include "ringbuffer.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief pmsx003 uart is UART4 in interrupt mode, debug output is USART1
 */
extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart1;

#define PMSX003_UART              (&huart4)
#define PMSX003_DEBUG_UART        (&huart1)
#define PMSX003_TX_TIMEOUT_MS     (100U)
#define PMSX003_DEBUG_BUF_LEN     (256U)

/**
 * @brief pmsx003 receive ring buffer, filled one byte at a time from the UART4 isr
 */
static RingBuffer gs_rx_buf;
static volatile uint8_t gs_rx_byte;
static volatile uint8_t gs_rx_running = 0;

/**
 * @brief  arm the next single byte interrupt reception
 * @return status code
 *         - 0 success
 *         - 1 start failed
 * @note   none
 */
static uint8_t a_pmsx003_rx_start(void)
{
    if (HAL_UART_Receive_IT(PMSX003_UART, (uint8_t *)&gs_rx_byte, 1) != HAL_OK)
    {
        gs_rx_running = 0;

        return 1;
    }
    gs_rx_running = 1;

    return 0;
}

/**
 * @brief     uart rx complete callback
 * @param[in] *huart pointer to a uart handle
 * @note      pushes the received byte into the ring buffer and re-arms reception
 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == UART4)
    {
        uint8_t byte = gs_rx_byte;

        /* drop the byte when the buffer is full, the frame parser resyncs on the 0x42 0x4D header */
        (void)RingBuffer_Write(&gs_rx_buf, &byte, 1);
        (void)a_pmsx003_rx_start();
    }
}

/**
 * @brief     uart error callback
 * @param[in] *huart pointer to a uart handle
 * @note      clears the error flags and restarts reception
 */
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == UART4)
    {
        __HAL_UART_CLEAR_OREFLAG(huart);
        __HAL_UART_CLEAR_NEFLAG(huart);
        __HAL_UART_CLEAR_FEFLAG(huart);
        __HAL_UART_CLEAR_PEFLAG(huart);
        (void)a_pmsx003_rx_start();
    }
}

/**
 * @brief  interface uart init
 * @return status code
 *         - 0 success
 *         - 1 uart init failed
 * @note   none
 */
uint8_t pmsx003_interface_uart_init(void)
{
    RingBuffer_Init(&gs_rx_buf);

    return a_pmsx003_rx_start();
}

/**
 * @brief  interface uart deinit
 * @return status code
 *         - 0 success
 *         - 1 uart deinit failed
 * @note   none
 */
uint8_t pmsx003_interface_uart_deinit(void)
{
    if (HAL_UART_AbortReceive_IT(PMSX003_UART) != HAL_OK)
    {
        return 1;
    }
    gs_rx_running = 0;
    RingBuffer_Init(&gs_rx_buf);

    return 0;
}

/**
 * @brief      interface uart read
 * @param[out] *buf pointer to a data buffer
 * @param[in]  len length of the data buffer
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 * @note       none
 */
uint16_t pmsx003_interface_uart_read(uint8_t *buf, uint16_t len)
{
    uint16_t n;

    if ((buf == NULL) || (len == 0))
    {
        return 0;
    }

    /* the isr writes head only and this reader writes tail only, so only the isr must be held off */
    __HAL_UART_DISABLE_IT(PMSX003_UART, UART_IT_RXNE);
    n = RingBuffer_Read(&gs_rx_buf, buf, len);
    if (gs_rx_running != 0)
    {
        __HAL_UART_ENABLE_IT(PMSX003_UART, UART_IT_RXNE);
    }

    return n;
}

/**
 * @brief  interface uart flush
 * @return status code
 *         - 0 success
 *         - 1 uart flush failed
 * @note   none
 */
uint8_t pmsx003_interface_uart_flush(void)
{
    __HAL_UART_DISABLE_IT(PMSX003_UART, UART_IT_RXNE);
    RingBuffer_Init(&gs_rx_buf);
    if (gs_rx_running != 0)
    {
        __HAL_UART_ENABLE_IT(PMSX003_UART, UART_IT_RXNE);
    }

    return 0;
}

/**
 * @brief     interface uart write
 * @param[in] *buf pointer to a data buffer
 * @param[in] len length of the data buffer
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 * @note      none
 */
uint8_t pmsx003_interface_uart_write(uint8_t *buf, uint16_t len)
{
    if ((buf == NULL) || (len == 0))
    {
        return 1;
    }

    /* commands are at most 7 bytes, a blocking send keeps the rx interrupt path untouched */
    if (HAL_UART_Transmit(PMSX003_UART, buf, len, PMSX003_TX_TIMEOUT_MS) != HAL_OK)
    {
        return 1;
    }

    return 0;
}

/**
 * @brief  interface reset gpio init
 * @return status code
 *         - 0 success
 *         - 1 reset gpio init failed
 * @note   none
 */
uint8_t pmsx003_interface_reset_gpio_init(void)
{
#ifdef PMSX003_RESET_Pin
    GPIO_InitTypeDef init = {0};

    init.Pin = PMSX003_RESET_Pin;
    init.Mode = GPIO_MODE_OUTPUT_PP;
    init.Pull = GPIO_NOPULL;
    init.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(PMSX003_RESET_GPIO_Port, &init);
    HAL_GPIO_WritePin(PMSX003_RESET_GPIO_Port, PMSX003_RESET_Pin, GPIO_PIN_SET);
#endif

    return 0;
}

/**
 * @brief  interface reset gpio deinit
 * @return status code
 *         - 0 success
 *         - 1 reset gpio deinit failed
 * @note   none
 */
uint8_t pmsx003_interface_reset_gpio_deinit(void)
{
#ifdef PMSX003_RESET_Pin
    HAL_GPIO_DeInit(PMSX003_RESET_GPIO_Port, PMSX003_RESET_Pin);
#endif

    return 0;
}

/**
 * @brief     interface reset gpio write
 * @param[in] level gpio level
 * @return    status code
 *            - 0 success
 *            - 1 reset gpio write failed
 * @note      none
 */
uint8_t pmsx003_interface_reset_gpio_write(uint8_t level)
{
#ifdef PMSX003_RESET_Pin
    HAL_GPIO_WritePin(PMSX003_RESET_GPIO_Port, PMSX003_RESET_Pin,
                      (level != 0) ? GPIO_PIN_SET : GPIO_PIN_RESET);
#else
    (void)level;
#endif

    return 0;
}

/**
 * @brief  interface set gpio init
 * @return status code
 *         - 0 success
 *         - 1 set gpio init failed
 * @note   none
 */
uint8_t pmsx003_interface_set_gpio_init(void)
{
#ifdef PMSX003_SET_Pin
    GPIO_InitTypeDef init = {0};

    init.Pin = PMSX003_SET_Pin;
    init.Mode = GPIO_MODE_OUTPUT_PP;
    init.Pull = GPIO_NOPULL;
    init.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(PMSX003_SET_GPIO_Port, &init);
    HAL_GPIO_WritePin(PMSX003_SET_GPIO_Port, PMSX003_SET_Pin, GPIO_PIN_SET);
#endif

    return 0;
}

/**
 * @brief  interface set gpio deinit
 * @return status code
 *         - 0 success
 *         - 1 set gpio deinit failed
 * @note   none
 */
uint8_t pmsx003_interface_set_gpio_deinit(void)
{
#ifdef PMSX003_SET_Pin
    HAL_GPIO_DeInit(PMSX003_SET_GPIO_Port, PMSX003_SET_Pin);
#endif

    return 0;
}

/**
 * @brief     interface set gpio write
 * @param[in] level gpio level
 * @return    status code
 *            - 0 success
 *            - 1 set gpio write failed
 * @note      none
 */
uint8_t pmsx003_interface_set_gpio_write(uint8_t level)
{
#ifdef PMSX003_SET_Pin
    HAL_GPIO_WritePin(PMSX003_SET_GPIO_Port, PMSX003_SET_Pin,
                      (level != 0) ? GPIO_PIN_SET : GPIO_PIN_RESET);
#else
    (void)level;
#endif

    return 0;
}

/**
 * @brief     interface delay ms
 * @param[in] ms time
 * @note      none
 */
void pmsx003_interface_delay_ms(uint32_t ms)
{
    HAL_Delay(ms);
}

/**
 * @brief     interface print format data
 * @param[in] fmt format data
 * @note      none
 */
void pmsx003_interface_debug_print(const char *const fmt, ...)
{
    char str[PMSX003_DEBUG_BUF_LEN];
    va_list args;
    int n;

    va_start(args, fmt);
    n = vsnprintf(str, sizeof(str), fmt, args);
    va_end(args);

    if (n <= 0)
    {
        return;
    }
    if ((size_t)n >= sizeof(str))
    {
        n = (int)sizeof(str) - 1;
    }

    (void)HAL_UART_Transmit(PMSX003_DEBUG_UART, (uint8_t *)str, (uint16_t)n, PMSX003_TX_TIMEOUT_MS);
}
