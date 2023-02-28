CONF_DIR ?= config

ifdef ORIG
SOURCE_FILES = xtensa-config.c \
	       $(CONF_DIR)/%/binutils/xtensa-modules.c \
	       $(CONF_DIR)/%/gdb/xtensa-config.c \
	       $(CONF_DIR)/%/gdb/xtensa-xtregs.c

INCLUDE += -Iinclude \
           -I$(CONF_DIR)/$*/binutils \
           -I$(CONF_DIR)/$*/xtensa/config
else
SOURCE_FILES = xtensa-config.c \
	       $(CONF_DIR)/%/binutils/bfd/xtensa-modules.c \
	       $(CONF_DIR)/%/gdb/gdb/xtensa-config.c \
	       $(CONF_DIR)/%/gdb/gdb/xtensa-xtregs.c

INCLUDE += -Iinclude \
           -I$(CONF_DIR)/$*/binutils/include
endif

CFLAGS += $(INCLUDE) -fPIC -O2

%.so: $(SOURCE_FILES)
	$(CC) -shared $(CFLAGS) $^ -o $@

.PHONY: libs
libs: $(patsubst $(CONF_DIR)/%,%.so,$(wildcard $(CONF_DIR)/*))

.PHONY: clean
clean:
	rm -fr *.so

.PHONY: install
install: libs
	mkdir -p $(DESTDIR)$(PREFIX)/lib
	cp -f *.so $(DESTDIR)$(PREFIX)/lib
