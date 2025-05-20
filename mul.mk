all: default

TOPNAME = mul
SIM_TOPNAME = mul_sim
VERILATOR_CFLAGS = --trace-fst
INC_PATH ?=

include ./general.mk
