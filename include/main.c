#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "history.h"

int main(void)
{
    char input[1024];

    while (1)
    {
        printf("shellforge$ ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL)
            break;

        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0)
            continue;

        add_history_command(input);

        if (strcmp(input, "history") == 0)
        {
            show_history();
            continue;
        }

        if (strcmp(input, "exit") == 0)
        {
            break;
        }

        printf("Command: %s\n", input);
    }

    return 0;
}
