all: default

TOPNAME = addsub8
VERILATOR_CFLAGS = --trace-fst
INC_PATH ?=

include ./general.mk
