HOST_GCC = gcc
SOURCE_FILES = xtensa-config.c config/$(CONFIG)/binutils/bfd/xtensa-modules.c
CFLAGS += -Iconfig/$(CONFIG)/binutils/include -I$(BINUTILS_DIR)/include -fPIC -O2

xtensa-config-$(CONFIG).so: $(SOURCE_FILES)
	$(HOST_GCC) -shared $(CFLAGS) $^ -o $@
