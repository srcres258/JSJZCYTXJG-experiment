all: default

TOPNAME = dffe
VERILATOR_CFLAGS = --trace-fst
INC_PATH ?=
NXDC_FILES = constr/dffe.nxdc

include ./general_nvboard.mk
