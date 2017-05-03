HOST_GCC = g++
TARGET_GCC ?= xtensa-linux-gcc
PLUGIN_SOURCE_FILES = xtensa-gcc-config.c
GCCPLUGINS_DIR := $(shell $(TARGET_GCC) -print-file-name=plugin)
CXXFLAGS += -I$(GCCPLUGINS_DIR)/include -I../config/$(CONFIG)/gcc/include -fPIC -fno-rtti -O2

xtensa-gcc-config-$(CONFIG).so: $(PLUGIN_SOURCE_FILES)
	$(HOST_GCC) -shared $(CXXFLAGS) $^ -o $@
