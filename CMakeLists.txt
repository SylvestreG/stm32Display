project(stm32Display C CXX ASM)

enable_language(C CXX ASM)

cmake_minimum_required(VERSION 3.7)

include_directories(src/libcpp/ src/libc/ src/include/)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T ${CMAKE_SOURCE_DIR}/scripts/script.ld")

add_subdirectory(src/libc)
add_subdirectory(src/libcpp)

add_executable(kernel   	src/dev/gpio.cpp
				src/dev/rcc.cpp
				src/locore/start.c
				src/sys/debug.cpp
				src/sys/kern_main.cpp)

target_link_libraries(kernel minic minicpp)

add_custom_command(OUTPUT kernel.ihex
                   COMMAND ${CMAKE_OBJCOPY} --output-format=binary kernel kernel.ihex
                   DEPENDS kernel
                   COMMENT "extract raw file")
add_custom_target(kernel.bin ALL DEPENDS kernel.ihex)
