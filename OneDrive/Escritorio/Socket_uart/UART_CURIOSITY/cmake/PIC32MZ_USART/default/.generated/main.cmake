include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(PIC32MZ_USART_default_library_list )

# Handle files with suffix s, for group default-XC32
if(PIC32MZ_USART_default_default_XC32_FILE_TYPE_assemble)
add_library(PIC32MZ_USART_default_default_XC32_assemble OBJECT ${PIC32MZ_USART_default_default_XC32_FILE_TYPE_assemble})
    PIC32MZ_USART_default_default_XC32_assemble_rule(PIC32MZ_USART_default_default_XC32_assemble)
    list(APPEND PIC32MZ_USART_default_library_list "$<TARGET_OBJECTS:PIC32MZ_USART_default_default_XC32_assemble>")
endif()

# Handle files with suffix S, for group default-XC32
if(PIC32MZ_USART_default_default_XC32_FILE_TYPE_assembleWithPreprocess)
add_library(PIC32MZ_USART_default_default_XC32_assembleWithPreprocess OBJECT ${PIC32MZ_USART_default_default_XC32_FILE_TYPE_assembleWithPreprocess})
    PIC32MZ_USART_default_default_XC32_assembleWithPreprocess_rule(PIC32MZ_USART_default_default_XC32_assembleWithPreprocess)
    list(APPEND PIC32MZ_USART_default_library_list "$<TARGET_OBJECTS:PIC32MZ_USART_default_default_XC32_assembleWithPreprocess>")
endif()

# Handle files with suffix [cC], for group default-XC32
if(PIC32MZ_USART_default_default_XC32_FILE_TYPE_compile)
add_library(PIC32MZ_USART_default_default_XC32_compile OBJECT ${PIC32MZ_USART_default_default_XC32_FILE_TYPE_compile})
    PIC32MZ_USART_default_default_XC32_compile_rule(PIC32MZ_USART_default_default_XC32_compile)
    list(APPEND PIC32MZ_USART_default_library_list "$<TARGET_OBJECTS:PIC32MZ_USART_default_default_XC32_compile>")
endif()

# Handle files with suffix cpp, for group default-XC32
if(PIC32MZ_USART_default_default_XC32_FILE_TYPE_compile_cpp)
add_library(PIC32MZ_USART_default_default_XC32_compile_cpp OBJECT ${PIC32MZ_USART_default_default_XC32_FILE_TYPE_compile_cpp})
    PIC32MZ_USART_default_default_XC32_compile_cpp_rule(PIC32MZ_USART_default_default_XC32_compile_cpp)
    list(APPEND PIC32MZ_USART_default_library_list "$<TARGET_OBJECTS:PIC32MZ_USART_default_default_XC32_compile_cpp>")
endif()

add_executable(${PIC32MZ_USART_default_image_name} ${PIC32MZ_USART_default_library_list})

target_link_libraries(${PIC32MZ_USART_default_image_name} PRIVATE ${PIC32MZ_USART_default_default_XC32_FILE_TYPE_link})

# Add the link options from the rule file.
PIC32MZ_USART_default_link_rule(${PIC32MZ_USART_default_image_name})

# Add bin2hex target for converting built file to a .hex file.
add_custom_target(PIC32MZ_USART_default_Bin2Hex ALL
    ${MP_BIN2HEX} ${PIC32MZ_USART_default_image_name})
add_dependencies(PIC32MZ_USART_default_Bin2Hex ${PIC32MZ_USART_default_image_name})

# Post build target to copy built file to the output directory.
add_custom_command(TARGET ${PIC32MZ_USART_default_image_name} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E make_directory ${PIC32MZ_USART_default_output_dir}
                    COMMAND ${CMAKE_COMMAND} -E copy ${PIC32MZ_USART_default_image_name} ${PIC32MZ_USART_default_output_dir}/${PIC32MZ_USART_default_original_image_name}
                    BYPRODUCTS ${PIC32MZ_USART_default_output_dir}/${PIC32MZ_USART_default_original_image_name})
