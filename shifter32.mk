all: default

TOPNAME = shifter32
VERILATOR_CFLAGS = --trace-fst
INC_PATH ?=

include ./general.mk
