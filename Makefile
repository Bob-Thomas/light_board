#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2015
#
# This file is in the public domain.
#
#############################################################################

TARGET     ?= arduino_due
SEARCH     += hwlib

SOURCES    +=  src/ADXL335.cpp src/color.cpp src/led_strip.cpp src/HCSR04.cpp src/light_board.cpp
HEADERS    += src/ADXL335.h src/config.h src/color.h src/led_strip.h src/HCSR04.h src/light_board.h
# set BMPTK to the next higher directory
BMPTK := $(BMPTK)bmptk/
# Defer to the next higher Makefile.inc to do the work
include $(BMPTK)Makefile.inc
