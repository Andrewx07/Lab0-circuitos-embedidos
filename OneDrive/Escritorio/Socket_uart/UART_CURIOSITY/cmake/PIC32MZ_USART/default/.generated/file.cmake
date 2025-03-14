# The following variables contains the files used by the different stages of the build process.
set(PIC32MZ_USART_default_default_XC32_FILE_TYPE_assemble)
set(PIC32MZ_USART_default_default_XC32_FILE_TYPE_assembleWithPreprocess
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/config/default/interrupts_a.S"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MZ/port_asm.S")
set_source_files_properties(${PIC32MZ_USART_default_default_XC32_FILE_TYPE_assembleWithPreprocess} PROPERTIES LANGUAGE C)
set(PIC32MZ_USART_default_default_XC32_FILE_TYPE_compile
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/app.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/config/default/driver/usart/src/drv_usart.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/config/default/exceptions.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/config/default/freertos_hooks.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/config/default/initialization.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/config/default/interrupts.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/config/default/osal/osal_freertos.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/config/default/peripheral/clk/plib_clk.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/config/default/peripheral/evic/plib_evic.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/config/default/peripheral/gpio/plib_gpio.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/config/default/peripheral/uart/plib_uart2.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/config/default/stdio/xc32_monitor.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/config/default/system/int/src/sys_int.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/config/default/tasks.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/third_party/rtos/FreeRTOS/Source/FreeRTOS_tasks.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/third_party/rtos/FreeRTOS/Source/croutine.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/third_party/rtos/FreeRTOS/Source/event_groups.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/third_party/rtos/FreeRTOS/Source/list.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MZ/port.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_1.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/third_party/rtos/FreeRTOS/Source/queue.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/third_party/rtos/FreeRTOS/Source/stream_buffer.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/third_party/rtos/FreeRTOS/Source/timers.c")
set(PIC32MZ_USART_default_default_XC32_FILE_TYPE_compile_cpp)
set(PIC32MZ_USART_default_default_XC32_FILE_TYPE_link)

# The linker script used for the build.
set(PIC32MZ_USART_default_LINKER_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/../../../src/config/default/p32MZ2048EFM144.ld")

# The (internal) path to the resulting build image.
set(PIC32MZ_USART_default_internal_image_name "${CMAKE_CURRENT_SOURCE_DIR}/../../../_build/PIC32MZ_USART/default/default.elf")

# The name of the resulting image, including namespace for configuration.
set(PIC32MZ_USART_default_image_name "PIC32MZ_USART_default_default.elf")

# The name of the image, excluding the namespace for configuration.
set(PIC32MZ_USART_default_original_image_name "default.elf")

# The output directory of the final image.
set(PIC32MZ_USART_default_output_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../../out/PIC32MZ_USART")
