# STM32F446RETx and PSM5003

## pin connections

usart to user

- PA10 (usart1_rx) -> tx stlink
- PA9 (usart1_5x) -> rx stlink

uart4 to pms5003

- PA0 (uart4_tx) -> rx pms5003
- PA1 (uart4_rx) -> tx pms5003

i2c1 to SSD1106 1.3 inch LCD (NOT CONNECTED, DON'T IMPLEMENT)

## driver

for UART connection to user, use `ringbuffer.h` and `ringbuffer.c`

## components

- board: https://github.com/WeActStudio/WeActStudio.STM32F4_64Pin_CoreBoard
- driver: https://github.com/libdriver/pmsx003

## ignore or maybe later

SET and RESET pins are not set, so those functions compile as no-ops behind #ifdef PMSX003_SET_Pin / PMSX003_RESET_Pin. To enable them:

1. Open pms5003.ioc in STM32CubeMX.
2. Pinout view -> click a free pin (e.g. PB0) -> select GPIO_Output. Repeat for a second pin (e.g. PB1).
3. Right-click PB0 -> Enter User Label -> PMSX003_SET. Right-click PB1 -> PMSX003_RESET.
4. System Core -> GPIO -> for both pins set: Output Level High, Mode Output Push Pull, Pull-up/Pull-down No pull-up and no pull-down, Speed Low.
