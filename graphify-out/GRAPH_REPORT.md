# Graph Report - .  (2026-07-29)

## Corpus Check
- Corpus is ~18,572 words - fits in a single context window. You may not need a graph.

## Summary
- 130 nodes · 188 edges · 14 communities (12 shown, 2 thin omitted)
- Extraction: 91% EXTRACTED · 9% INFERRED · 0% AMBIGUOUS · INFERRED: 17 edges (avg confidence: 0.8)
- Token cost: 0 input · 0 output

## Community Hubs (Navigation)
- PMS UART Interface Layer
- PMSx003 Sensor Driver
- Newlib Syscall Stubs
- Application Main Loop
- HAL MSP Peripheral Init
- SH1106 u8g2 Port
- System Clock Startup

## God Nodes (most connected - your core abstractions)
1. `main()` - 19 edges
2. `Error_Handler()` - 10 edges
3. `RingBuffer_Init()` - 6 edges
4. `pmsx003_read()` - 6 edges
5. `RingBuffer_Write()` - 5 edges
6. `a_pmsx003_make_frame()` - 5 edges
7. `pmsx003_set_mode()` - 5 edges
8. `a_pmsx003_rx_start()` - 4 edges
9. `HAL_UART_RxCpltCallback()` - 4 edges
10. `pmsx003_interface_debug_print()` - 4 edges

## Surprising Connections (you probably didn't know these)
- `main()` --calls--> `u8g2_port_init()`  [INFERRED]
  pms5003/Core/Src/main.c → pms5003/Core/Src/u8g2_port.c
- `pmsx003_interface_uart_deinit()` --calls--> `RingBuffer_Init()`  [INFERRED]
  pms5003/Core/Src/driver_pmsx003_interface.c → pms5003/Core/Src/ringbuffer.c
- `main()` --calls--> `pmsx003_interface_uart_flush()`  [INFERRED]
  pms5003/Core/Src/main.c → pms5003/Core/Src/driver_pmsx003_interface.c
- `PMS_Init()` --calls--> `pmsx003_init()`  [INFERRED]
  pms5003/Core/Src/main.c → pms5003/Drivers/PMS5003/driver_pmsx003.c
- `main()` --calls--> `RingBuffer_Init()`  [INFERRED]
  pms5003/Core/Src/main.c → pms5003/Core/Src/ringbuffer.c

## Import Cycles
- None detected.

## Communities (14 total, 2 thin omitted)

### Community 0 - "PMS UART Interface Layer"
Cohesion: 0.13
Nodes (16): a_pmsx003_rx_start(), UART_HandleTypeDef, HAL_UART_ErrorCallback(), HAL_UART_RxCpltCallback(), pmsx003_interface_uart_deinit(), pmsx003_interface_uart_flush(), pmsx003_interface_uart_init(), pmsx003_interface_uart_read() (+8 more)

### Community 1 - "PMSx003 Sensor Driver"
Cohesion: 0.19
Nodes (19): a_pmsx003_make_frame(), a_pmsx003_parse_data(), a_pmsx003_parse_frame(), pmsx003_data_t, pmsx003_deinit(), pmsx003_get_buffer(), pmsx003_info(), pmsx003_init() (+11 more)

### Community 3 - "Application Main Loop"
Cohesion: 0.25
Nodes (16): pmsx003_interface_debug_print(), pmsx003_data_t, Error_Handler(), I2C_Scan(), main(), MX_DMA_Init(), MX_GPIO_Init(), MX_I2C1_Init() (+8 more)

### Community 5 - "HAL MSP Peripheral Init"
Cohesion: 0.24
Nodes (9): I2C_HandleTypeDef, UART_HandleTypeDef, HAL_I2C_MspDeInit(), HAL_I2C_MspInit(), HAL_RTC_MspDeInit(), HAL_RTC_MspInit(), HAL_UART_MspDeInit(), HAL_UART_MspInit() (+1 more)

### Community 6 - "SH1106 u8g2 Port"
Cohesion: 0.50
Nodes (4): u8g2_port_init(), u8x8_byte_stm32_hw_i2c(), u8x8_gpio_and_delay_stm32(), u8x8_t

## Knowledge Gaps
- **2 thin communities (<3 nodes) omitted from report** — run `graphify query` to explore isolated nodes.

## Suggested Questions
_Questions this graph is uniquely positioned to answer:_

- **Why does `main()` connect `Application Main Loop` to `PMS UART Interface Layer`, `PMSx003 Sensor Driver`, `SH1106 u8g2 Port`?**
  _High betweenness centrality (0.252) - this node is a cross-community bridge._
- **Why does `pmsx003_read()` connect `PMSx003 Sensor Driver` to `Application Main Loop`?**
  _High betweenness centrality (0.133) - this node is a cross-community bridge._
- **Why does `Error_Handler()` connect `Application Main Loop` to `HAL MSP Peripheral Init`?**
  _High betweenness centrality (0.093) - this node is a cross-community bridge._
- **Are the 5 inferred relationships involving `main()` (e.g. with `pmsx003_interface_debug_print()` and `pmsx003_interface_uart_flush()`) actually correct?**
  _`main()` has 5 INFERRED edges - model-reasoned connections that need verification._
- **Are the 3 inferred relationships involving `Error_Handler()` (e.g. with `HAL_I2C_MspInit()` and `HAL_RTC_MspInit()`) actually correct?**
  _`Error_Handler()` has 3 INFERRED edges - model-reasoned connections that need verification._
- **Are the 4 inferred relationships involving `RingBuffer_Init()` (e.g. with `pmsx003_interface_uart_deinit()` and `pmsx003_interface_uart_flush()`) actually correct?**
  _`RingBuffer_Init()` has 4 INFERRED edges - model-reasoned connections that need verification._
- **Should `PMS UART Interface Layer` be split into smaller, more focused modules?**
  _Cohesion score 0.12615384615384614 - nodes in this community are weakly interconnected._