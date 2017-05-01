#include <xtensa-config.h>
#include <gcc-plugin.h>

int plugin_is_GPL_compatible = 1;

static const struct xtensa_config this_xtensa_config =
XTENSA_CONFIG_INITIALIZER;

static void fn(void *gcc_data, void *user_data)
{
	xtensa_config = &this_xtensa_config;
}

int plugin_init (struct plugin_name_args *plugin_info,
		 struct plugin_gcc_version *version)
{
	register_callback("", PLUGIN_PRAGMAS, fn, NULL);
	return 0;
}
