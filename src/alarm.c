#include "alarm.h"

#define _POSIX_SOURCE 1 // POSIX compliant source

// Alarm function handler
void alarmHandler(int signal) {
    int alarmCount = 1;
    alarmCount++;

    printf("\nAlarm #%d\n", alarmCount);
}

//Starts the alarm
int startAlarm(int timeout) {
    int alarmEnabled = FALSE;

    // Set alarm function handler
    (void) signal(SIGALRM, alarmHandler);

    alarm(timeout);
    alarmEnabled = TRUE;

    return 0;
}
