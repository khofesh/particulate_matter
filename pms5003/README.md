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
