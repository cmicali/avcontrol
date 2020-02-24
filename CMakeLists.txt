cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(CMAKE_CXX_STANDARD 11)
set(PROJECT_NAME avcontrol)
project(${PROJECT_NAME})

#set(${PROJECT_NAME}_SKETCH avcontrol_main.cpp)
set(${PROJECT_NAME}_BOARD leonardoeth)

# Define additional source and header files or default arduino sketch files
set(${PROJECT_NAME}_SRCS
        avcontrol_main.cpp
        AVNetwork.cpp
        Knob.cpp
        Encoder.cpp
        LEDRing.cpp
        Util.cpp
)
set(${PROJECT_NAME}_HDRS
        AVNetwork.h
        Knob.h
        Encoder.h
        LEDRing.h
        Util.h
)

include_directories(
        libs
        libs/SPI/src
        libs/Ethernet/src
        libs/Adafruit_NeoPixel
)

link_directories(libs)

set(_RECURSE True)


#### Additional settings for programmer. From programmers.txt
set(${PROJECT_NAME}_PROGRAMMER avrispmkii)
set(${PROJECT_NAME}_PORT /dev/cu.usbmodem14301)
set(leonardoeth.upload.speed 9600)

## Verbose build process
# set(${PROJECT_NAME}_AFLAGS -v)

generate_arduino_firmware(${PROJECT_NAME})

print_board_list()
print_programmer_list()
