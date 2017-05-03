#include <xtensa-config.h>
#include <gcc-plugin.h>

int plugin_is_GPL_compatible = 1;

static const struct xtensa_config this_xtensa_config =
XTENSA_CONFIG_INITIALIZER;

int plugin_init (struct plugin_name_args *plugin_info,
		 struct plugin_gcc_version *version)
{
	xtensa_config = &this_xtensa_config;
	return 0;
}
