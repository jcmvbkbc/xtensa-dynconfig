HOST_GCC = gcc
PLUGIN_SOURCE_FILES = xtensa-binutils-config.c ../config/$(CONFIG)/binutils/bfd/xtensa-modules.c
CFLAGS += -I../config/$(CONFIG)/binutils/include -I$(BINUTILSPLUGINS_DIR)/include -fPIC -O2

xtensa-binutils-config-$(CONFIG).so: $(PLUGIN_SOURCE_FILES)
	$(HOST_GCC) -shared $(CFLAGS) $^ -o $@
