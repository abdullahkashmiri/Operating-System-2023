#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t parentID = getpid();
    int STATE = 1;

    int numOfLaps, lapTimeLimit;
    printf("Enter Number of Laps> ");
    scanf("%d", &numOfLaps);
    printf("Enter Lap Time Limit (in seconds)> ");
    scanf("%d", &lapTimeLimit);

    pid_t lapCounterProcess = fork();
    if (lapCounterProcess == 0)
    {
        printf("Child 1 with ID: %d\n", getpid());

        int lap = 0;
        int seconds = 0;

        printf("Lap #: %d\n", lap);
        while (STATE)
        {
            sleep(1);
            seconds++;
            if (seconds == lapTimeLimit)
            {
                lap++;
                printf("Lap #: %d\n", lap);
                seconds = 0;
            }
            if (lap == numOfLaps)
            {
                STATE = 0;
            }
        }
    }
    else
    {
        pid_t totalTimeCounterProcess = fork();
        if (totalTimeCounterProcess == 0)
        {
            printf("Child 2 with ID: %d\n", getpid());

            int lap = 0;
            int hours = 0, minutes = 0, seconds = 0, lapSeconds = 0;

            while (STATE)
            {
                sleep(1);
                seconds++;
                lapSeconds++;

                if (seconds == 60)
                {
                    minutes++;
                    seconds = 0;
                }
                if (minutes == 60)
                {
                    hours++;
                    minutes = 0;
                }
                if (lapSeconds == lapTimeLimit)
                {
                    lap++;
                    lapSeconds = 0;
                }
                if (lap == numOfLaps)
                {
                    STATE = 0;
                }
            }
            sleep(0.20);
            printf("Total Time: %d Hours, %d Minutes and %d Seconds\n", hours, minutes, seconds);
        }
    }

    if (parentID == getpid())
    {
        wait(NULL);
        wait(NULL);
        if (fork() == 0)
        {
            printf("Child 3 with ID: %d\n", getpid());
            printf("Name: ABC, Reg #: 1234\n");
        }
        else
        {
            wait(NULL);
        }
    }
    return 0;
}
