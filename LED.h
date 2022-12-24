#ifndef LED_H
#define LED_H

#define LED_0 "/sys/class/leds/beaglebone:green:usr0/brightness"
#define LED_1 "/sys/class/leds/beaglebone:green:usr1/brightness"
#define LED_2 "/sys/class/leds/beaglebone:green:usr2/brightness"
#define LED_3 "/sys/class/leds/beaglebone:green:usr3/brightness"
#define LED_0_TRIGGER "/sys/class/leds/beaglebone:green:usr0/trigger"
#define LED_1_TRIGGER "/sys/class/leds/beaglebone:green:usr1/trigger"
#define LED_2_TRIGGER "/sys/class/leds/beaglebone:green:usr2/trigger"
#define LED_3_TRIGGER "/sys/class/leds/beaglebone:green:usr3/trigger"
#define NONE "none"

void writeToLED(char *value, char *path);
void initializeLEDS();
void setLEDS(char *led, char *ONorOFF);

#endif