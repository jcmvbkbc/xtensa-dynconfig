#include <stdlib.h>
#define XTENSA_CONFIG_DEFINITION
#include <xtensa-config.h>
#include <xtensa-dynconfig.h>

#undef XTENSA_CONFIG_ENTRY
#define XTENSA_CONFIG_ENTRY(a) a
struct xtensa_config xtensa_config = XTENSA_CONFIG_INITIALIZER;

#define _STRINGIFY(a) #a
#define STRINGIFY(a) _STRINGIFY(a)

#undef XTENSA_CONFIG_ENTRY
#define XTENSA_CONFIG_ENTRY(a) "__" #a "=" STRINGIFY(a)
const char *xtensa_config_strings[] = {
	XTENSA_CONFIG_ENTRY_LIST,
	NULL,
};
