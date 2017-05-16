HOST_GCC = gcc
SOURCE_FILES = xtensa-config.c \
	       config/$(CONFIG)/binutils/bfd/xtensa-modules.c \
	       config/$(CONFIG)/gdb/gdb/xtensa-config.c \
	       config/$(CONFIG)/gdb/gdb/xtensa-xtregs.c
INCLUDE += -I. \
	   -Iconfig/$(CONFIG)/binutils/include \
	   -I$(BINUTILS_DIR)/include \
	   -I$(BINUTILS_DIR)/gdb

CFLAGS += $(INCLUDE) -fPIC -O2

xtensa-config-$(CONFIG).so: $(SOURCE_FILES)
	$(HOST_GCC) -shared $(CFLAGS) $^ -o $@
