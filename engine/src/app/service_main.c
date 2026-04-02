#include "cli/command_runner.h"

int auth_service_main(int argc, char **argv)
{
    return cli_command_runner_run(argc, argv);
}
