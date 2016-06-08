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

SOURCES    += src/color.cpp src/led_strip.cpp
HEADERS    += src/color.h src/led_strip.h
# set BMPTK to the next higher directory
BMPTK := $(BMPTK)bmptk/
# Defer to the next higher Makefile.inc to do the work
include $(BMPTK)Makefile.inc
