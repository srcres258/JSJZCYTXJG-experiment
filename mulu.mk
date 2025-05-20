all: default

TOPNAME = mulu
SIM_TOPNAME = mulu_sim
VERILATOR_CFLAGS = --trace-fst
INC_PATH ?=

include ./general.mk
