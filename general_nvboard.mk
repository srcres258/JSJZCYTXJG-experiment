VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert \
				-I$(abspath ./vsrc/$(TOPNAME))

SIM_TOPNAME ?= $(TOPNAME)

BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

default: $(BIN)

$(shell mkdir -p $(BUILD_DIR))

# constraint file
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@
auto_bind: $(SRC_AUTO_BIND)

# project source
VSRCS = $(shell find $(abspath ./vsrc/$(TOPNAME)) -name "$(TOPNAME).v")
CSRCS = $(shell find $(abspath ./csrc/$(TOPNAME)) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
CSRCS += $(SRC_AUTO_BIND)

# rules for NVBoard
# 把NVBoard的Makefile包括进来，构建程序包括NVBoard界面
include $(NVBOARD_HOME)/scripts/nvboard.mk

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(SIM_TOPNAME)\""

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(SIM_TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

run: $(BIN)
	@$^

clean:
	rm -rf $(BUILD_DIR)

gen_header:
	$(VERILATOR) --top-module $(SIM_TOPNAME) --Mdir $(OBJ_DIR) --cc $(VSRCS) \
		-I$(abspath ./vsrc/$(TOPNAME))

.PHONY: default all clean run sim auto_bind gen_header
