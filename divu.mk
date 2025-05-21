all: default

TOPNAME = divu
SIM_TOPNAME = divu_sim
VERILATOR_CFLAGS = --trace-fst
INC_PATH ?=

include ./general.mk
