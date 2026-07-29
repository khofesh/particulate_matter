#ifndef __U8G2_PORT_H
#define __U8G2_PORT_H

#include "u8g2.h"

extern u8g2_t gs_u8g2;

/* returns 0 on success, 1 if the panel did not ack */
uint8_t u8g2_port_init(void);

uint8_t u8x8_byte_stm32_hw_i2c(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);
uint8_t u8x8_gpio_and_delay_stm32(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);

#endif /* __U8G2_PORT_H */
