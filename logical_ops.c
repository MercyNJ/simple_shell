
 #include "main.h"

/*bool handle_logic(char **argv)
{
    bool success = true; 
    bool short_circuit = false;

    while (*argv != NULL)
    {
        if (strcmp(*argv, "&&") == 0)
        {
            argv++;
            if (*argv != NULL && !short_circuit)
            {
                success = execution(argv);
                if (!success)
                {
                    short_circuit = true;
                }
            }
        }
        else if (strcmp(*argv, "||") == 0)
        {
            argv++;
            if (*argv != NULL && !short_circuit)
            {
                success = execution(argv);
                if (success)
                {
                    short_circuit = true;
                }
            }
        }
        else
        {
            success = execution(argv);
            if (!success)
            {
                short_circuit = true;
            }
        }
        argv++;
    }

    return success;
}
*/
