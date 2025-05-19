all: default

TOPNAME = andgate
SIM_TOPNAME = andgate_sim
VERILATOR_CFLAGS = --trace-fst
INC_PATH ?=

include ./general.mk
