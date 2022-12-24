#ifndef BUTTON_H
#define BUTTON_H
#define BUTTON_CONFIG "config-pin p8.43 gpio"
#define USER_PORT_DIRECTION "echo in > /sys/class/gpio/gpio72/direction"
#define USER_PORT_ACTIVE "echo 1 > /sys/class/gpio/gpio72/active_low"
#define USER_PORT "/sys/class/gpio/gpio72/value"
#define _POSIX_C_SOURCE 200809L

void runCommand(char *command);
void initializeButton();
int readFromButton();

#endif