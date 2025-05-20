all: default

TOPNAME = mux2x1verilog
VERILATOR_CFLAGS = --trace-fst
INC_PATH ?=

include ./general.mk
