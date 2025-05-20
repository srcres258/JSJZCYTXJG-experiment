all: default

TOPNAME = barrelshifter8
VERILATOR_CFLAGS = --trace-fst
INC_PATH ?=

include ./general.mk
