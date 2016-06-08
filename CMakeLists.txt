cmake_minimum_required(VERSION 3.2)
project(lightboard)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/hwlib")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/bmptk")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/bmptk/targets/cortex/atmel")

#
# To enable code auto-completion, please specify path
# to main source file (*.c, *.cpp) and uncomment line below
#
add_executable(lightboard
        src/main.cpp
        src/color.h
        src/color.cpp
        src/led_strip.h
        src/led_strip.cpp
        src/ADXL335.cpp
        src/HCSR04.cpp
        src/HCSR04.h
        src/light_board.cpp
        src/light_board.h src/config.h)
