project(stm32Display)

cmake_minimum_required(VERSION 3.7)

include_directories(src/libcpp/ src/libc/ src/include/)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T ${CMAKE_SOURCE_DIR}/scripts/script.ld")

add_subdirectory(src/libc)
add_subdirectory(src/libcpp)

add_executable(${PROJECT_NAME}	src/dev/gpio.cpp
				src/dev/rcc.cpp
				src/locore/start.c
				src/sys/debug.cpp
				src/sys/kern_main.cpp)

target_link_libraries(${PROJECT_NAME} minic minicpp)
message(INFO ${CMAKE_OBJCOPY})
add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.ihex
	COMMAND ${CMAKE_OBJCOPY} --output-format=binary ${CMAKE_BINARY_DIR}/${PROJECT_NAME}
	COMMAND ${CMAKE_OBJCOPY} ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.ihex
	DEPENDS ${PROJECT_NAME}
	COMMENT "extract raw file")
add_custom_target(${PROJECT_NAME}.ihex ALL DEPENDS ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
