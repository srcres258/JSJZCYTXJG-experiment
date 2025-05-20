all: default

TOPNAME = mux4to1
VERILATOR_CFLAGS = --trace-fst
INC_PATH ?=

include ./general.mk
