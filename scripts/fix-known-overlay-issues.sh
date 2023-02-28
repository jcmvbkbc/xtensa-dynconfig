#! /bin/sh

find -name xtensa-modules.c -print0 | xargs -0 \
	sed \
	-e 's/^\(xtensa_opcode_encode_fn.*\[\] =\)/static \1/' \
	-e '/^int num_bypass_groups()/,/}/d' \
	-e '/^int num_bypass_group_chunks()/,/}/d' \
	-e '/^uint32 \*bypass_entry(int i)/,/}/d' \
	-e '/^Slot_[a-zA-Z0-9_]\+_decode (const xtensa_insnbuf insn)/,/^}/s/^  return 0;$/  return XTENSA_UNDEFINED;/' \
	-i

find -name xtensa-config.c -print0 | xargs -0 \
	sed \
	-e 's/^\(xtensa_reg_mask_t xtensa_submask.*\[\] =\)/static \1/' \
	-e 's/^\(const xtensa_mask_t xtensa_mask.* =\)/static \1/' \
	-i
