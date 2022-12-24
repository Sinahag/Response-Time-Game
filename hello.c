#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <sys/wait.h>
#include "LED.h"
#include "button.h"

#define MAX_TIME 5000

// need to choose between trigger or delay_on or delay_off or brightness files
// types of triggers: none || timer || heartbeat
// note timer needs to be on to be able to use delays

static void sleepForMs(long long delayInMs)
{
    const long long NS_PER_MS = 1000 * 1000;
    const long long NS_PER_SECOND = 1000000000;
    long long delayNs = delayInMs * NS_PER_MS;
    int seconds = delayNs / NS_PER_SECOND;
    int nanoseconds = delayNs % NS_PER_SECOND;
    struct timespec reqDelay = {seconds, nanoseconds};
    nanosleep(&reqDelay, (struct timespec *)NULL);
}

static long long getTimeInMs(void)
{
    struct timespec spec;
    clock_gettime(CLOCK_REALTIME, &spec);
    long long seconds = spec.tv_sec;
    long long nanoSeconds = spec.tv_nsec;
    long long milliSeconds = seconds * 1000 + nanoSeconds / 1000000;
    return milliSeconds;
}

void displaySummary(long long time, long long bestTime)
{
    if (time <= bestTime)
    {
        printf("New best time!\n");
    }
    printf("Your reaction time was %lldms; best so far in game is %lldms.\n", time, bestTime);
}

int main(void)
{
    long long responseTime = MAX_TIME;
    long long bestTime = MAX_TIME;
    long long startTime;
    long long endTime;
    long long waitFor;
    int button;
    initializeButton();
    initializeLEDS();
    button = readFromButton();

    printf("Hello embedded world, from Sina!\n\nWhen LED3 lights up, press USER button!\n");

    while (1)
    {
        while (button == 1)
        { // busy wait while button is pressed
            button = readFromButton();
        }

        // turn on LED 0
        setLEDS(LED_0, "1");
        waitFor = rand() % (MAX_TIME / 2 + 500) + 500;
        sleepForMs(waitFor);       // wait for 2 seconds
        button = readFromButton(); // check if user is pressing USER too soon

        if (button != 1)
        {
            setLEDS(LED_3, "1");
            startTime = getTimeInMs();
            while (button != 1)
            {
                button = readFromButton();
            }
            endTime = getTimeInMs();

            responseTime = endTime - startTime;
            if (responseTime > MAX_TIME)
            {
                printf("No input within %dms; quitting!\n", MAX_TIME);
                setLEDS(NULL, "0"); // shut off LEDS
                break;
            }
        }
        else
        {
            responseTime = MAX_TIME;
        }

        // light up all LEDS
        setLEDS(NULL, "1");
        sleepForMs(100);

        if (responseTime < bestTime)
        {
            bestTime = responseTime;
        }
        // Display Summary
        displaySummary(responseTime, bestTime);

        setLEDS(NULL, "0"); // shut off LEDS
    }

    return 0;
}