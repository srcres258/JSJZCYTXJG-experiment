all: default

TOPNAME = addsub
SIM_TOPNAME = addsub_sim
VERILATOR_CFLAGS = --trace-fst
INC_PATH ?=

include ./general.mk
