cmake_minimum_required(VERSION 3.30)

# Pull in SDK (must be before project)
include("$ENV{PICO_SDK_PATH}\\external\\pico_sdk_import.cmake")

project(pico-robot C CXX ASM)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)

if (PICO_SDK_VERSION_STRING VERSION_LESS "2.0.0")
        message(FATAL_ERROR "Raspberry Pi Pico SDK version 2.0.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

# Initialize the SDK
pico_sdk_init()

add_compile_options(-Wall
        -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
        -Wno-unused-function # we have some for the docs that aren't called
        -Wno-maybe-uninitialized
        )

configure_file( config.h.in ${CMAKE_BINARY_DIR}/generated/pico-robot/config.h )
include_directories( ${CMAKE_BINARY_DIR}/generated/pico-robot/ ) 

add_library(pico-robot STATIC
        src/math/random.cpp
        src/kinematics/differentialdrive.cpp
        src/board/temperature.cpp

        src/packets/control/xbox.cpp
        )
        
target_include_directories(pico-robot PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/include
        ${CMAKE_CURRENT_LIST_DIR}/..
        )
target_link_libraries(pico-robot
        pico_stdlib
        hardware_adc
        pico_rand
        )