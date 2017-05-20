SOURCE_FILES = xtensa-config.c \
	       config/$(CONFIG)/binutils/bfd/xtensa-modules.c \
	       config/$(CONFIG)/gdb/gdb/xtensa-config.c \
	       config/$(CONFIG)/gdb/gdb/xtensa-xtregs.c
INCLUDE += -Iinclude \
	   -Iconfig/$(CONFIG)/binutils/include

CFLAGS += $(INCLUDE) -fPIC -O2

xtensa-config-$(CONFIG).so: $(SOURCE_FILES)
	$(CC) -shared $(CFLAGS) $^ -o $@
