#include "u8g2_port.h"
#include "main.h"

extern I2C_HandleTypeDef hi2c1;

u8g2_t gs_u8g2;

/* u8g2_SendBuffer pushes one tile row at a time: 16 tiles * 8 bytes + 1 control byte */
#define U8G2_I2C_BUF_SIZE 160

static uint8_t gs_i2c_buf[U8G2_I2C_BUF_SIZE];
static uint8_t gs_i2c_len;

uint8_t u8x8_byte_stm32_hw_i2c(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
  uint8_t *data;

  switch (msg)
  {
    case U8X8_MSG_BYTE_INIT:
      /* hi2c1 is already brought up by MX_I2C1_Init */
      break;

    case U8X8_MSG_BYTE_START_TRANSFER:
      gs_i2c_len = 0;
      break;

    case U8X8_MSG_BYTE_SEND:
      data = (uint8_t *)arg_ptr;
      if ((uint16_t)gs_i2c_len + arg_int > U8G2_I2C_BUF_SIZE)
      {
        return 0;
      }
      while (arg_int > 0)
      {
        gs_i2c_buf[gs_i2c_len++] = *data++;
        arg_int--;
      }
      break;

    case U8X8_MSG_BYTE_END_TRANSFER:
      /* u8x8 stores the address in 8 bit form, which is what HAL expects */
      if (HAL_I2C_Master_Transmit(&hi2c1, u8x8_GetI2CAddress(u8x8),
                                  gs_i2c_buf, gs_i2c_len, 100) != HAL_OK)
      {
        return 0;
      }
      break;

    case U8X8_MSG_BYTE_SET_DC:
      /* not used on i2c, the control byte carries dc */
      break;

    default:
      return 0;
  }

  return 1;
}

uint8_t u8x8_gpio_and_delay_stm32(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
  (void)u8x8;
  (void)arg_ptr;

  switch (msg)
  {
    case U8X8_MSG_GPIO_AND_DELAY_INIT:
      break;

    case U8X8_MSG_DELAY_MILLI:
      HAL_Delay(arg_int);
      break;

    case U8X8_MSG_DELAY_10MICRO:
    case U8X8_MSG_DELAY_100NANO:
    case U8X8_MSG_DELAY_NANO:
      /* at 180 MHz the call overhead alone already covers these */
      break;

    default:
      return 0;
  }

  return 1;
}

uint8_t u8g2_port_init(void)
{
  if (HAL_I2C_IsDeviceReady(&hi2c1, 0x78, 3, 10) != HAL_OK)
  {
    return 1;
  }

  u8g2_Setup_sh1106_i2c_128x64_noname_f(&gs_u8g2, U8G2_R0,
                                        u8x8_byte_stm32_hw_i2c,
                                        u8x8_gpio_and_delay_stm32);
  u8g2_SetI2CAddress(&gs_u8g2, 0x78);
  u8g2_InitDisplay(&gs_u8g2);
  u8g2_SetPowerSave(&gs_u8g2, 0);
  u8g2_ClearBuffer(&gs_u8g2);
  u8g2_SendBuffer(&gs_u8g2);

  return 0;
}
