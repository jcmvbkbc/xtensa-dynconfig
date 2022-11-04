This GCC/binutils/GDB plugin configures xtensa GCC, binutils and GDB for the
specific xtensa CPU. It will only load into GCC, binutils and GDB versions
that support such dynamic configuration. Without this plugin GCC and binutils
will produce code for the default xtensa core: the FSF one, or for the core
configured with the xtensa configuration overlay.

## Building

Install configuration overlays for the xtensa core targets into the directory
named `config` and run:

```
  make
```

or specify config directory manually:

```
  make CONF_DIR=<path>
```

## Using

Set the environment variable XTENSA_GNU_CONFIG to the path of the
configuration shared object:

```
  $ export XTENSA_GNU_CONFIG=`pwd`/<config-name>.so
```

Run the compiler, assembler, linker, debugger or other binutils as usual.

Dynamic configuration works both for cross and native toolchain.
The following parts of the toolchain still need to be configured statically:
- target gdbserver needs proper include/xtensa-config.h
  gdb/gdbserver/xtensa-config.c and gdb/gdbserver/xtensa-xtregs.c in the
  binutils-gdb.

## Note

the GCC Runtime Library Exception
(https://www.gnu.org/licenses/gcc-exception-3.1.en.html) has rules that apply
here. If you want to distribute the binary produced by GCC using this plugin,
the plugin code (including the xtensa configuration overlay) must be available
under a GPL-compatible license. The people to whom you distribute the binary
produced by GCC must be able to themselves build the plugin used to create
the binary.
