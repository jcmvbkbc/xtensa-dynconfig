#define XTENSA_CONFIG_DEFINITION
#include <xtensa-config.h>
#include <xtensa-dynconfig.h>

static struct xtensa_config this_xtensa_config = XTENSA_CONFIG_INITIALIZER;

struct xtensa_config *xtensa_config(void)
{
    return &this_xtensa_config;
}
