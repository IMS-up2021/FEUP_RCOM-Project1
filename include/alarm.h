#ifndef ALARM_H
#define ALARM_H

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

#define FALSE 0
#define TRUE 1

void alarmHandler(int signal);

int startAlarm(int timeout);

#endif // ALARM_H

