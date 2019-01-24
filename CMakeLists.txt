cmake_minimum_required(VERSION 3.0.2)
## Configure the AVR toolchain
include( ${CMAKE_CURRENT_LIST_DIR}/generic-gcc-avr.cmake)

find_program(AVR_GCC NAMES avr-gcc)
find_program(AVR_GXX NAMES avr-g++)
find_program(AVR_DUDE NAMES avrdude)
find_program(AVR_OBJCOPY NAMES avr-objcopy)

set(CMAKE_C_COMPILER ${AVR_GCC})
set(CMAKE_CXX_COMPILER ${AVR_GXX})
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")

project(hw2 CXX C)

set(DEVICE atmega328p)
set(MCU atmega328p)
set(AVRDUDE_DEVICE m328p)
#set(DEVICE atmega168)
#set(MCU atmega168)
#set(AVRDUDE_DEVICE m168)
#if( UNIX AND NOT APPLE ) # GUESS for linux
  ## UNCOMMENT THIS LINE AND MODIFY ON YOUR MAC OR LINUX LAPTOP; SEE INSTRUCTIONS ON ICON
#   set(PORT "/dev/tty.usbmodem00128351")
#endif()

set(CMAKE_C_FLAGS "-g -Wall -mcall-prologues -mmcu=${MCU} ${DEVICE_SPECIFIC_CFLAGS} -Os -std=c99")
set(CMAKE_CXX_FLAGS "-g -Wall -mcall-prologues -mmcu=${MCU} ${DEVICE_SPECIFIC_CFLAGS} -fno-exceptions -Os -std=c++11")
set(CMAKE_LDFLAGS "-Wl,-gc-sections  -Wl,-relax")

if(NOT PORT)
  find_file(PORT NAMES ttyACM0 PATHS /dev)
endif()

if(NOT PORT)
  message(STATUS "\nWARNING:\nWARNING:\nSERIAL PORT FOR DOWNLOADING TO ROBOT IS NOT SET\n\n")
  message(STATUS "Set PORT to \"UNKNOWN\" if you just want to compile, but do not want to program the robot")
  message(STATUS "See: https://www.pololu.com/docs/0J36/5.b for identifying the port on a mac computer")
  message(STATUS "\nWARNING:\nWARNING:\nSERIAL PORT FOR DOWNLOADING TO ROBOT IS NOT SET\n\n")
  ## ls /dev/tty.usbmodem* , and choose one with smallest number
  set(PORT "/dev/ttyACM0" CACHE PATH "A guess for the port to use" FORCE)  ## NOTE THIS IS A GUESS! That usually works for linux
endif()

message(STATUS "Using port ${PORT}")

set(PROGNAME hw3)

add_executable(${PROGNAME}.obj ${PROGNAME}.cpp pid.h trackSelect.h robotHelperFunctions.cpp robotHelperFunctions.h trackAndPiDFunctions.cpp trackAndPiDFunctions.h)
target_link_libraries(${PROGNAME}.obj pololu_${DEVICE})

#add_custom_command(TARGET ${PROGNAME}.obj
#                   POST_BUILD
#                   COMMENT "OBJ2HEX conversion")

add_custom_target(flash
                  COMMAND ${AVR_OBJCOPY} -R .eeprom -O ihex ${PROGNAME}.obj ${PROGNAME}.hex
                  COMMAND ${AVR_DUDE} -p  ${AVRDUDE_DEVICE} -c avrisp2 -P ${PORT} -U flash:w:${PROGNAME}.hex
                  DEPENDS ${PROGNAME}.obj
                  COMMENT "dump program to the robot on port ${PORT}")

