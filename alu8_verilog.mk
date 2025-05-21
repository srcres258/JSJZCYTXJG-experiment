all: default

TOPNAME = alu8_verilog
VERILATOR_CFLAGS = --trace-fst
INC_PATH ?=

include ./general.mk
