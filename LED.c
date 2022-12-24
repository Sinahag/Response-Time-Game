#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "LED.h"

void writeToLED(char *value, char *path)
{
    // Use fopen() to open the file for write access.
    FILE *pFile = fopen(path, "w");
    if (pFile == NULL)
    {
        printf("ERROR: Unable to open export file.\n");
        exit(1);
    }
    // Write to data to the file using fprintf():
    fprintf(pFile, "%s", value);
    // Close the file using fclose():
    fclose(pFile);
}
void initializeLEDS(){
    writeToLED(NONE, LED_0_TRIGGER);
    writeToLED(NONE, LED_1_TRIGGER);
    writeToLED(NONE, LED_2_TRIGGER);
    writeToLED(NONE, LED_3_TRIGGER);
}

void setLEDS(char *led, char *ONorOFF)
{
    if (led != NULL)
    {
        writeToLED(ONorOFF, led);
    }
    else
    {
        writeToLED(ONorOFF, LED_0);
        writeToLED(ONorOFF, LED_1);
        writeToLED(ONorOFF, LED_2);
        writeToLED(ONorOFF, LED_3);
    }
}
