all: default

TOPNAME = ram16x8
VERILATOR_CFLAGS = --trace-fst
INC_PATH ?=

include ./general.mk
