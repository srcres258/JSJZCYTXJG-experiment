all: default

TOPNAME = ram64x8
VERILATOR_CFLAGS = --trace-fst
INC_PATH ?=

include ./general.mk
