# Graph Report - .  (2026-07-28)

## Corpus Check
- Large corpus: 100 files · ~714,652 words. Semantic extraction will be expensive (many Claude tokens). Consider running on a subfolder.

## Summary
- 2750 nodes · 6643 edges · 76 communities (71 shown, 5 thin omitted)
- Extraction: 95% EXTRACTED · 5% INFERRED · 0% AMBIGUOUS · INFERRED: 328 edges (avg confidence: 0.8)
- Token cost: 0 input · 0 output

## Community Hubs (Navigation)
- LL RTC Register Layer
- LL USART Register Layer
- CMSIS GCC Intrinsics
- CMSIS ARMClang Intrinsics
- LL I2C Register Layer
- Cortex-M MPU and Cache
- HAL UART Driver
- LL RCC Clock Control
- LL RCC Clock Headers
- HAL RTC Driver
- ARMClang SIMD Intrinsics
- Cortex-M Core Peripherals
- LL Power Control
- Cortex-M85 Core and PAC
- IAR Compiler Intrinsics
- LL DMA Stream Config
- HAL Flash Programming
- LL DMA Transfer Control
- LL DMA Interrupt Flags
- Armv8.1-M Mainline Core
- Cortex-M55 Core
- Armv8-M Mainline Core
- Cortex-M33 Core
- Cortex-M35P Core
- LL SYSCFG and DBGMCU
- LL System Config Headers
- Armv8-M Baseline Core
- Cortex-M23 Core
- LL Bus Clock Gating
- HAL I2C State Machine
- HAL I2C Transfer API
- HAL Power and I2C Modes
- HAL Tick and DBGMCU
- LL Cortex SysTick
- ARMCC Compiler Intrinsics
- LL GPIO Config
- Cortex-M3 Core
- Cortex-M7 Core
- SecurCore SC300
- HAL DMA Driver
- PMSx003 Sensor Driver
- HAL Power Driver
- HAL Cortex NVIC and MPU
- Newlib Syscall Stubs
- HAL RCC Extended Clocks
- Cortex-M0 Core
- Cortex-M0+ Core
- LL EXTI Lines
- HAL RCC Driver
- Armv8 Performance Monitor
- Application Main and MSP
- HAL EXTI Driver
- HAL GPIO Driver
- MSP Peripheral Init
- HAL DMA Extended
- LL Utils and Delay
- System Clock Startup
- Flash RAM Functions
- ARMClang Bit Helpers
- GCC Saturation Intrinsics
- GCC Packing Intrinsics
- HAL I2C Extended
- LL RTC Backup Registers
- LL RTC Tamper Config
- Driver Licensing
- HAL I2C State Types
- ARMClang Misc Intrinsics
- GCC Misc Intrinsics

## God Nodes (most connected - your core abstractions)
1. `__DSB()` - 97 edges
2. `__ISB()` - 77 edges
3. `HAL_GetTick()` - 54 edges
4. `HAL_I2C_EV_IRQHandler()` - 18 edges
5. `HAL_DMA_Start_IT()` - 16 edges
6. `I2C_WaitOnFlagUntilTimeout()` - 16 edges
7. `FLASH_WaitForLastOperation()` - 14 edges
8. `HAL_DMA_Abort_IT()` - 13 edges
9. `RTC_EnterInitMode()` - 12 edges
10. `RTC_ExitInitMode()` - 12 edges

## Surprising Connections (you probably didn't know these)
- `I2C1_EV_IRQHandler()` --calls--> `HAL_I2C_EV_IRQHandler()`  [INFERRED]
  pms5003/Core/Src/stm32f4xx_it.c → pms5003/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c.c
- `I2C1_ER_IRQHandler()` --calls--> `HAL_I2C_ER_IRQHandler()`  [INFERRED]
  pms5003/Core/Src/stm32f4xx_it.c → pms5003/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c.c
- `__NVIC_SystemReset()` --calls--> `__DSB()`  [INFERRED]
  pms5003/Drivers/CMSIS/Include/core_armv81mml.h → pms5003/Drivers/CMSIS/Include/cmsis_gcc.h
- `__NVIC_SystemReset()` --calls--> `__DSB()`  [INFERRED]
  pms5003/Drivers/CMSIS/Include/core_armv8mbl.h → pms5003/Drivers/CMSIS/Include/cmsis_gcc.h
- `__NVIC_SystemReset()` --calls--> `__DSB()`  [INFERRED]
  pms5003/Drivers/CMSIS/Include/core_armv8mml.h → pms5003/Drivers/CMSIS/Include/cmsis_gcc.h

## Import Cycles
- None detected.

## Communities (76 total, 5 thin omitted)

### Community 0 - "LL RTC Register Layer"
Cohesion: 0.03
Nodes (182): __STATIC_INLINE, LL_RTC_ALMA_ConfigTime(), LL_RTC_ALMA_Disable(), LL_RTC_ALMA_DisableWeekday(), LL_RTC_ALMA_Enable(), LL_RTC_ALMA_EnableWeekday(), LL_RTC_ALMA_GetDay(), LL_RTC_ALMA_GetMask() (+174 more)

### Community 1 - "LL USART Register Layer"
Cohesion: 0.04
Nodes (136): __STATIC_INLINE, LL_USART_ClearFlag_FE(), LL_USART_ClearFlag_IDLE(), LL_USART_ClearFlag_LBD(), LL_USART_ClearFlag_nCTS(), LL_USART_ClearFlag_NE(), LL_USART_ClearFlag_ORE(), LL_USART_ClearFlag_PE() (+128 more)

### Community 2 - "CMSIS GCC Intrinsics"
Cohesion: 0.03
Nodes (132): __CLREX(), __CLZ(), __cmsis_start(), __disable_fault_irq(), __disable_irq(), __enable_fault_irq(), __enable_irq(), __get_APSR() (+124 more)

### Community 3 - "CMSIS ARMClang Intrinsics"
Cohesion: 0.03
Nodes (115): __CLZ(), __disable_fault_irq(), __disable_irq(), __enable_fault_irq(), __enable_irq(), __get_APSR(), __get_BASEPRI(), __get_CONTROL() (+107 more)

### Community 4 - "LL I2C Register Layer"
Cohesion: 0.05
Nodes (111): I2C_TypeDef, __STATIC_INLINE, LL_I2C_AcknowledgeNextData(), LL_I2C_ClearFlag_ADDR(), LL_I2C_ClearFlag_AF(), LL_I2C_ClearFlag_ARLO(), LL_I2C_ClearFlag_BERR(), LL_I2C_ClearFlag_OVR() (+103 more)

### Community 5 - "Cortex-M MPU and Cache"
Cohesion: 0.05
Nodes (106): MPU_Type, __STATIC_FORCEINLINE, SCB_CleanDCache(), SCB_CleanDCache_by_Addr(), SCB_CleanInvalidateDCache(), SCB_CleanInvalidateDCache_by_Addr(), SCB_DisableDCache(), SCB_DisableICache() (+98 more)

### Community 6 - "HAL UART Driver"
Cohesion: 0.06
Nodes (89): HAL_UART_CallbackIDTypeDef, HAL_UART_RxEventTypeTypeDef, HAL_UART_StateTypeDef, DMA1_Stream0_IRQHandler(), DMA1_Stream2_IRQHandler(), DMA1_Stream4_IRQHandler(), DMA1_Stream6_IRQHandler(), I2C1_ER_IRQHandler() (+81 more)

### Community 7 - "LL RCC Clock Control"
Cohesion: 0.02
Nodes (84): LL_RCC_ClearFlag_HSECSS(), LL_RCC_ClearFlag_HSIRDY(), LL_RCC_ClearFlag_PLLI2SRDY(), LL_RCC_ClearResetFlags(), LL_RCC_DisableIT_HSERDY(), LL_RCC_DisableIT_LSERDY(), LL_RCC_DisableIT_LSIRDY(), LL_RCC_DisableIT_PLLSAIRDY() (+76 more)

### Community 8 - "LL RCC Clock Headers"
Cohesion: 0.02
Nodes (85): __STATIC_INLINE, LL_RCC_ClearFlag_HSERDY(), LL_RCC_ClearFlag_LSERDY(), LL_RCC_ClearFlag_LSIRDY(), LL_RCC_ClearFlag_PLLRDY(), LL_RCC_ClearFlag_PLLSAIRDY(), LL_RCC_ConfigMCO(), LL_RCC_DisableIT_HSIRDY() (+77 more)

### Community 9 - "HAL RTC Driver"
Cohesion: 0.07
Nodes (78): HAL_RTC_CallbackIDTypeDef, HAL_RTCStateTypeDef, HAL_StatusTypeDef, RTC_DateTypeDef, RTC_HandleTypeDef, RTC_TimeTypeDef, __weak, HAL_StatusTypeDef (+70 more)

### Community 10 - "ARMClang SIMD Intrinsics"
Cohesion: 0.05
Nodes (69): __CLZ(), __disable_fault_irq(), __disable_irq(), __enable_fault_irq(), __enable_irq(), __get_APSR(), __get_BASEPRI(), __get_CONTROL() (+61 more)

### Community 11 - "Cortex-M Core Peripherals"
Cohesion: 0.06
Nodes (62): packed, __PACKED_STRUCT, T_UINT16_READ(), T_UINT16_WRITE(), T_UINT32(), T_UINT32_READ(), T_UINT32_WRITE(), IRQn_Type (+54 more)

### Community 12 - "LL Power Control"
Cohesion: 0.06
Nodes (62): __STATIC_INLINE, LL_PWR_ClearFlag_SB(), LL_PWR_ClearFlag_UD(), LL_PWR_ClearFlag_WU(), LL_PWR_DisableBkUpAccess(), LL_PWR_DisableBkUpRegulator(), LL_PWR_DisableFLASHInterfaceSTOP(), LL_PWR_DisableFLASHMemorySTOP() (+54 more)

### Community 13 - "Cortex-M85 Core and PAC"
Cohesion: 0.08
Nodes (56): DCB_GetAuthCtrl(), DCB_SetAuthCtrl(), DIB_GetAuthStatus(), IRQn_Type, __STATIC_INLINE, ITM_CheckChar(), ITM_ReceiveChar(), ITM_SendChar() (+48 more)

### Community 14 - "IAR Compiler Intrinsics"
Cohesion: 0.07
Nodes (55): __IAR_FT, __CLZ(), __get_APSR(), __get_MSPLIM(), __get_PSPLIM(), __packed, __STATIC_FORCEINLINE, __STATIC_INLINE (+47 more)

### Community 15 - "LL DMA Stream Config"
Cohesion: 0.04
Nodes (49): DMA_TypeDef, LL_DMA_ClearFlag_DME1(), LL_DMA_ClearFlag_DME2(), LL_DMA_ClearFlag_DME4(), LL_DMA_ClearFlag_DME7(), LL_DMA_ClearFlag_HT0(), LL_DMA_ClearFlag_HT3(), LL_DMA_ClearFlag_TC5() (+41 more)

### Community 16 - "HAL Flash Programming"
Cohesion: 0.10
Nodes (45): FLASH_AdvOBProgramInitTypeDef, FLASH_EraseInitTypeDef, FLASH_OBProgramInitTypeDef, HAL_StatusTypeDef, __weak, HAL_StatusTypeDef, FLASH_Erase_Sector(), FLASH_FlushCaches() (+37 more)

### Community 17 - "LL DMA Transfer Control"
Cohesion: 0.04
Nodes (48): LL_DMA_ClearFlag_DME3(), LL_DMA_ClearFlag_DME5(), LL_DMA_ClearFlag_FE0(), LL_DMA_ClearFlag_FE6(), LL_DMA_ClearFlag_FE7(), LL_DMA_ClearFlag_HT2(), LL_DMA_ClearFlag_TC2(), LL_DMA_ClearFlag_TC3() (+40 more)

### Community 18 - "LL DMA Interrupt Flags"
Cohesion: 0.04
Nodes (49): __STATIC_INLINE, LL_DMA_ClearFlag_DME0(), LL_DMA_ClearFlag_DME6(), LL_DMA_ClearFlag_FE1(), LL_DMA_ClearFlag_FE2(), LL_DMA_ClearFlag_FE3(), LL_DMA_ClearFlag_FE4(), LL_DMA_ClearFlag_FE5() (+41 more)

### Community 19 - "Armv8.1-M Mainline Core"
Cohesion: 0.10
Nodes (47): DCB_GetAuthCtrl(), DCB_SetAuthCtrl(), DIB_GetAuthStatus(), IRQn_Type, __STATIC_INLINE, ITM_CheckChar(), ITM_ReceiveChar(), ITM_SendChar() (+39 more)

### Community 20 - "Cortex-M55 Core"
Cohesion: 0.10
Nodes (47): DCB_GetAuthCtrl(), DCB_SetAuthCtrl(), DIB_GetAuthStatus(), IRQn_Type, __STATIC_INLINE, ITM_CheckChar(), ITM_ReceiveChar(), ITM_SendChar() (+39 more)

### Community 21 - "Armv8-M Mainline Core"
Cohesion: 0.10
Nodes (46): DCB_GetAuthCtrl(), DCB_SetAuthCtrl(), DIB_GetAuthStatus(), IRQn_Type, __STATIC_INLINE, ITM_CheckChar(), ITM_ReceiveChar(), ITM_SendChar() (+38 more)

### Community 22 - "Cortex-M33 Core"
Cohesion: 0.10
Nodes (46): DCB_GetAuthCtrl(), DCB_SetAuthCtrl(), DIB_GetAuthStatus(), IRQn_Type, __STATIC_INLINE, ITM_CheckChar(), ITM_ReceiveChar(), ITM_SendChar() (+38 more)

### Community 23 - "Cortex-M35P Core"
Cohesion: 0.10
Nodes (46): DCB_GetAuthCtrl(), DCB_SetAuthCtrl(), DIB_GetAuthStatus(), IRQn_Type, __STATIC_INLINE, ITM_CheckChar(), ITM_ReceiveChar(), ITM_SendChar() (+38 more)

### Community 24 - "LL SYSCFG and DBGMCU"
Cohesion: 0.05
Nodes (41): LL_DBGMCU_APB2_GRP1_FreezePeriph(), LL_DBGMCU_APB2_GRP1_UnFreezePeriph(), LL_DBGMCU_DisableDBGStandbyMode(), LL_DBGMCU_DisableDBGStopMode(), LL_DBGMCU_EnableDBGSleepMode(), LL_DBGMCU_EnableDBGStopMode(), LL_DBGMCU_GetRevisionID(), LL_DBGMCU_GetTracePinAssignment() (+33 more)

### Community 25 - "LL System Config Headers"
Cohesion: 0.05
Nodes (42): __STATIC_INLINE, LL_DBGMCU_APB1_GRP1_FreezePeriph(), LL_DBGMCU_APB1_GRP1_UnFreezePeriph(), LL_DBGMCU_DisableDBGSleepMode(), LL_DBGMCU_EnableDBGStandbyMode(), LL_DBGMCU_GetDeviceID(), LL_FLASH_DisableDataCacheReset(), LL_FLASH_DisableInstCache() (+34 more)

### Community 26 - "Armv8-M Baseline Core"
Cohesion: 0.12
Nodes (39): DCB_GetAuthCtrl(), DCB_SetAuthCtrl(), DIB_GetAuthStatus(), IRQn_Type, __STATIC_INLINE, __NVIC_ClearPendingIRQ(), NVIC_ClearTargetState(), NVIC_DecodePriority() (+31 more)

### Community 27 - "Cortex-M23 Core"
Cohesion: 0.12
Nodes (39): DCB_GetAuthCtrl(), DCB_SetAuthCtrl(), DIB_GetAuthStatus(), IRQn_Type, __STATIC_INLINE, __NVIC_ClearPendingIRQ(), NVIC_ClearTargetState(), NVIC_DecodePriority() (+31 more)

### Community 28 - "LL Bus Clock Gating"
Cohesion: 0.11
Nodes (36): __STATIC_INLINE, LL_AHB1_GRP1_DisableClock(), LL_AHB1_GRP1_DisableClockLowPower(), LL_AHB1_GRP1_EnableClock(), LL_AHB1_GRP1_EnableClockLowPower(), LL_AHB1_GRP1_ForceReset(), LL_AHB1_GRP1_IsEnabledClock(), LL_AHB1_GRP1_ReleaseReset() (+28 more)

### Community 29 - "HAL I2C State Machine"
Cohesion: 0.10
Nodes (36): HAL_I2C_CallbackIDTypeDef, HAL_I2C_ModeTypeDef, pI2C_AddrCallbackTypeDef, pI2C_CallbackTypeDef, HAL_StatusTypeDef, I2C_HandleTypeDef, HAL_I2C_DeInit(), HAL_I2C_DisableListen_IT() (+28 more)

### Community 30 - "HAL I2C Transfer API"
Cohesion: 0.15
Nodes (35): DMA_HandleTypeDef, __weak, HAL_I2C_AbortCpltCallback(), HAL_I2C_AddrCallback(), HAL_I2C_ER_IRQHandler(), HAL_I2C_ErrorCallback(), HAL_I2C_EV_IRQHandler(), HAL_I2C_ListenCpltCallback() (+27 more)

### Community 31 - "HAL Power and I2C Modes"
Cohesion: 0.12
Nodes (27): HAL_GetTick(), FlagStatus, HAL_I2C_IsDeviceReady(), HAL_I2C_Master_Receive(), HAL_I2C_Master_Transmit(), HAL_I2C_Mem_Read(), HAL_I2C_Mem_Write(), HAL_I2C_Slave_Receive() (+19 more)

### Community 32 - "HAL Tick and DBGMCU"
Cohesion: 0.08
Nodes (16): HAL_TickFreqTypeDef, HAL_StatusTypeDef, __weak, HAL_NVIC_SetPriorityGrouping(), HAL_SYSTICK_Config(), HAL_DeInit(), HAL_Delay(), HAL_GetTickFreq() (+8 more)

### Community 33 - "LL Cortex SysTick"
Cohesion: 0.14
Nodes (27): __STATIC_INLINE, LL_CPUID_GetConstant(), LL_CPUID_GetImplementer(), LL_CPUID_GetParNo(), LL_CPUID_GetRevision(), LL_CPUID_GetVariant(), LL_HANDLER_DisableFault(), LL_HANDLER_EnableFault() (+19 more)

### Community 34 - "ARMCC Compiler Intrinsics"
Cohesion: 0.14
Nodes (22): __get_APSR(), __get_BASEPRI(), __get_CONTROL(), __get_FAULTMASK(), __get_FPSCR(), __get_IPSR(), __get_MSP(), __get_PRIMASK() (+14 more)

### Community 35 - "LL GPIO Config"
Cohesion: 0.21
Nodes (25): GPIO_TypeDef, __STATIC_INLINE, LL_GPIO_GetAFPin_0_7(), LL_GPIO_GetAFPin_8_15(), LL_GPIO_GetPinMode(), LL_GPIO_GetPinOutputType(), LL_GPIO_GetPinPull(), LL_GPIO_GetPinSpeed() (+17 more)

### Community 36 - "Cortex-M3 Core"
Cohesion: 0.19
Nodes (23): IRQn_Type, __STATIC_INLINE, ITM_CheckChar(), ITM_ReceiveChar(), ITM_SendChar(), __NVIC_ClearPendingIRQ(), NVIC_DecodePriority(), __NVIC_DisableIRQ() (+15 more)

### Community 37 - "Cortex-M7 Core"
Cohesion: 0.19
Nodes (23): IRQn_Type, __STATIC_INLINE, ITM_CheckChar(), ITM_ReceiveChar(), ITM_SendChar(), __NVIC_ClearPendingIRQ(), NVIC_DecodePriority(), __NVIC_DisableIRQ() (+15 more)

### Community 38 - "SecurCore SC300"
Cohesion: 0.19
Nodes (23): IRQn_Type, __STATIC_INLINE, ITM_CheckChar(), ITM_ReceiveChar(), ITM_SendChar(), __NVIC_ClearPendingIRQ(), NVIC_DecodePriority(), __NVIC_DisableIRQ() (+15 more)

### Community 39 - "HAL DMA Driver"
Cohesion: 0.22
Nodes (21): HAL_DMA_CallbackIDTypeDef, HAL_DMA_LevelCompleteTypeDef, HAL_DMA_StateTypeDef, DMA_HandleTypeDef, HAL_StatusTypeDef, DMA_CalcBaseAndBitshift(), DMA_CheckFifoParam(), DMA_SetConfig() (+13 more)

### Community 40 - "PMSx003 Sensor Driver"
Cohesion: 0.19
Nodes (19): a_pmsx003_make_frame(), a_pmsx003_parse_data(), a_pmsx003_parse_frame(), pmsx003_deinit(), pmsx003_get_buffer(), pmsx003_info(), pmsx003_init(), pmsx003_read() (+11 more)

### Community 42 - "HAL Power Driver"
Cohesion: 0.11
Nodes (5): __weak, HAL_PWR_ConfigPVD(), HAL_PWR_PVD_IRQHandler(), HAL_PWR_PVDCallback(), PWR_PVDTypeDef

### Community 43 - "HAL Cortex NVIC and MPU"
Cohesion: 0.13
Nodes (12): MPU_Region_InitTypeDef, IRQn_Type, __weak, HAL_MPU_ConfigRegion(), HAL_MPU_Disable(), HAL_NVIC_ClearPendingIRQ(), HAL_NVIC_GetActive(), HAL_NVIC_GetPendingIRQ() (+4 more)

### Community 45 - "HAL RCC Extended Clocks"
Cohesion: 0.15
Nodes (15): HAL_StatusTypeDef, RCC_OscInitTypeDef, HAL_RCC_DeInit(), HAL_RCC_GetOscConfig(), HAL_RCC_OscConfig(), HAL_RCCEx_DisablePLLI2S(), HAL_RCCEx_DisablePLLSAI(), HAL_RCCEx_EnablePLLI2S() (+7 more)

### Community 46 - "Cortex-M0 Core"
Cohesion: 0.25
Nodes (17): IRQn_Type, __STATIC_INLINE, __NVIC_ClearPendingIRQ(), NVIC_DecodePriority(), __NVIC_DisableIRQ(), __NVIC_EnableIRQ(), NVIC_EncodePriority(), __NVIC_GetEnableIRQ() (+9 more)

### Community 47 - "Cortex-M0+ Core"
Cohesion: 0.25
Nodes (17): IRQn_Type, __STATIC_INLINE, __NVIC_ClearPendingIRQ(), NVIC_DecodePriority(), __NVIC_DisableIRQ(), __NVIC_EnableIRQ(), NVIC_EncodePriority(), __NVIC_GetEnableIRQ() (+9 more)

### Community 48 - "LL EXTI Lines"
Cohesion: 0.21
Nodes (17): __STATIC_INLINE, LL_EXTI_ClearFlag_0_31(), LL_EXTI_DisableEvent_0_31(), LL_EXTI_DisableFallingTrig_0_31(), LL_EXTI_DisableIT_0_31(), LL_EXTI_DisableRisingTrig_0_31(), LL_EXTI_EnableEvent_0_31(), LL_EXTI_EnableFallingTrig_0_31() (+9 more)

### Community 49 - "HAL RCC Driver"
Cohesion: 0.18
Nodes (14): HAL_StatusTypeDef, RCC_OscInitTypeDef, __weak, HAL_RCC_ClockConfig(), HAL_RCC_CSSCallback(), HAL_RCC_GetClockConfig(), HAL_RCC_GetHCLKFreq(), HAL_RCC_GetOscConfig() (+6 more)

### Community 50 - "Armv8 Performance Monitor"
Cohesion: 0.23
Nodes (15): ARM_PMU_CNTR_Disable(), ARM_PMU_CNTR_Enable(), ARM_PMU_CNTR_Increment(), ARM_PMU_CYCCNT_Reset(), ARM_PMU_Disable(), ARM_PMU_Enable(), ARM_PMU_EVCNTR_ALL_Reset(), ARM_PMU_Get_CCNTR() (+7 more)

### Community 51 - "Application Main and MSP"
Cohesion: 0.29
Nodes (13): Error_Handler(), main(), MX_DMA_Init(), MX_GPIO_Init(), MX_I2C1_Init(), MX_RTC_Init(), MX_UART4_Init(), MX_USART1_UART_Init() (+5 more)

### Community 52 - "HAL EXTI Driver"
Cohesion: 0.29
Nodes (13): EXTI_CallbackIDTypeDef, EXTI_ConfigTypeDef, EXTI_HandleTypeDef, HAL_StatusTypeDef, HAL_EXTI_ClearConfigLine(), HAL_EXTI_ClearPending(), HAL_EXTI_GenerateSWI(), HAL_EXTI_GetConfigLine() (+5 more)

### Community 53 - "HAL GPIO Driver"
Cohesion: 0.21
Nodes (13): GPIO_InitTypeDef, GPIO_PinState, GPIO_TypeDef, HAL_StatusTypeDef, __weak, HAL_GPIO_EXTI_Callback(), HAL_GPIO_EXTI_IRQHandler(), HAL_GPIO_Init() (+5 more)

### Community 55 - "MSP Peripheral Init"
Cohesion: 0.24
Nodes (9): I2C_HandleTypeDef, RTC_HandleTypeDef, UART_HandleTypeDef, HAL_I2C_MspDeInit(), HAL_RTC_MspDeInit(), HAL_RTC_MspInit(), HAL_UART_MspDeInit(), HAL_NVIC_DisableIRQ() (+1 more)

### Community 56 - "HAL DMA Extended"
Cohesion: 0.50
Nodes (7): HAL_DMA_MemoryTypeDef, DMA_HandleTypeDef, HAL_StatusTypeDef, DMA_MultiBufferSetConfig(), HAL_DMAEx_ChangeMemory(), HAL_DMAEx_MultiBufferStart(), HAL_DMAEx_MultiBufferStart_IT()

### Community 57 - "LL Utils and Delay"
Cohesion: 0.43
Nodes (7): __STATIC_INLINE, LL_GetFlashSize(), LL_GetPackageType(), LL_GetUID_Word0(), LL_GetUID_Word1(), LL_GetUID_Word2(), LL_InitTick()

### Community 59 - "Flash RAM Functions"
Cohesion: 0.33
Nodes (5): HAL_FLASHEx_DisableFlashSleepMode, HAL_FLASHEx_EnableFlashSleepMode, HAL_FLASHEx_StartFlashInterfaceClk, HAL_FLASHEx_StopFlashInterfaceClk, void()

### Community 60 - "ARMClang Bit Helpers"
Cohesion: 0.40
Nodes (5): __PACKED_STRUCT, T_UINT16_READ(), T_UINT16_WRITE(), T_UINT32_READ(), T_UINT32_WRITE()

### Community 61 - "GCC Saturation Intrinsics"
Cohesion: 0.40
Nodes (5): __PACKED_STRUCT, T_UINT16_READ(), T_UINT16_WRITE(), T_UINT32_READ(), T_UINT32_WRITE()

### Community 62 - "GCC Packing Intrinsics"
Cohesion: 0.40
Nodes (5): __ROR(), __SXTAB16(), __SXTAB16_RORn(), __SXTB16(), __SXTB16_RORn()

### Community 63 - "HAL I2C Extended"
Cohesion: 0.60
Nodes (4): HAL_StatusTypeDef, I2C_HandleTypeDef, HAL_I2CEx_ConfigAnalogFilter(), HAL_I2CEx_ConfigDigitalFilter()

### Community 64 - "LL RTC Backup Registers"
Cohesion: 0.50
Nodes (4): LL_RTC_ALMA_GetHour(), LL_RTC_ALMA_GetMinute(), LL_RTC_ALMA_GetSecond(), LL_RTC_ALMA_GetTime()

### Community 65 - "LL RTC Tamper Config"
Cohesion: 0.50
Nodes (4): LL_RTC_ALMB_GetHour(), LL_RTC_ALMB_GetMinute(), LL_RTC_ALMB_GetSecond(), LL_RTC_ALMB_GetTime()

### Community 66 - "Driver Licensing"
Cohesion: 0.67
Nodes (3): Apache-2.0 Terms (STM32F4xx CMSIS Device), Apache License 2.0 (CMSIS Core), BSD-3-Clause Terms (STM32F4xx HAL Driver)

## Knowledge Gaps
- **5 isolated node(s):** `v`, `v`, `v`, `Apache License 2.0 (CMSIS Core)`, `BSD-3-Clause Terms (STM32F4xx HAL Driver)`
  These have ≤1 connection - possible missing edges or undocumented components.
- **5 thin communities (<3 nodes) omitted from report** — run `graphify query` to explore isolated nodes.

## Suggested Questions
_Questions this graph is uniquely positioned to answer:_

- **Why does `__ISB()` connect `Cortex-M MPU and Cache` to `CMSIS GCC Intrinsics`, `CMSIS ARMClang Intrinsics`, `ARMClang SIMD Intrinsics`, `Cortex-M Core Peripherals`, `Cortex-M85 Core and PAC`, `HAL Flash Programming`, `Armv8.1-M Mainline Core`, `Cortex-M55 Core`, `Armv8-M Mainline Core`, `Cortex-M33 Core`, `Cortex-M35P Core`, `Armv8-M Baseline Core`, `Cortex-M23 Core`, `LL Cortex SysTick`, `ARMCC Compiler Intrinsics`, `Cortex-M3 Core`, `Cortex-M7 Core`, `SecurCore SC300`, `Cortex-M0 Core`, `Cortex-M0+ Core`?**
  _High betweenness centrality (0.301) - this node is a cross-community bridge._
- **Why does `HAL_GetTick()` connect `HAL Power and I2C Modes` to `HAL Tick and DBGMCU`, `HAL UART Driver`, `HAL DMA Driver`, `HAL RTC Driver`, `HAL RCC Extended Clocks`, `HAL Flash Programming`, `HAL RCC Driver`?**
  _High betweenness centrality (0.217) - this node is a cross-community bridge._
- **Why does `FLASH_Program_DoubleWord()` connect `HAL Flash Programming` to `Cortex-M MPU and Cache`?**
  _High betweenness centrality (0.215) - this node is a cross-community bridge._
- **What connects `v`, `v`, `v` to the rest of the system?**
  _5 weakly-connected nodes found - possible documentation gaps or missing edges._
- **Should `LL RTC Register Layer` be split into smaller, more focused modules?**
  _Cohesion score 0.03242658980363899 - nodes in this community are weakly interconnected._
- **Should `LL USART Register Layer` be split into smaller, more focused modules?**
  _Cohesion score 0.043151567196221555 - nodes in this community are weakly interconnected._
- **Should `CMSIS GCC Intrinsics` be split into smaller, more focused modules?**
  _Cohesion score 0.02984734563681932 - nodes in this community are weakly interconnected._