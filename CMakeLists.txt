project(stm32Display C)

cmake_minimum_required(VERSION 3.7)

include_directories(src/include/)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T ${CMAKE_SOURCE_DIR}/scripts/script.ld")

add_executable(${PROJECT_NAME}	src/dev/gpio.c
				src/dev/rcc.c
				src/locore/start.c
				src/libkern/memcpy.c
				src/libkern/memset.c
				src/libkern/strlen.c
				src/sys/debug.c
				src/sys/kern_main.c)

add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.ihex
	COMMAND ${CMAKE_OBJCOPY} --output-format=binary ${CMAKE_BINARY_DIR}/${PROJECT_NAME}
	COMMAND ${CMAKE_OBJCOPY} ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.ihex
	DEPENDS ${PROJECT_NAME} 
	COMMENT "extract raw file")
add_custom_target(${PROJECT_NAME}.ihex ALL DEPENDS ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
