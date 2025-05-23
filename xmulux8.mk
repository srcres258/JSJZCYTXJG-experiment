all: default

TOPNAME = xmulux8
VERILATOR_CFLAGS = --trace-fst
INC_PATH ?=
NXDC_FILES = constr/xmulux8.nxdc

include ./general_nvboard.mk
