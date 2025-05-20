all: default

TOPNAME = muxnto1
SIM_TOPNAME = muxnto1_sim
VERILATOR_CFLAGS = --trace-fst
INC_PATH ?=

include ./general.mk
