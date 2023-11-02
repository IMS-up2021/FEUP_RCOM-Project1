// Link layer header.
// NOTE: This file must not be changed.

#ifndef LINK_LAYER_H
#define LINK_LAYER_H

#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <termios.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

#define _POSIX_SOURCE 1
#define MAX_PAYLOAD_SIZE 1000
#define BAUDRATE 38400

// MISC
#define BUF_SIZE 256
#define FALSE 0
#define TRUE 1

#define FLAG 0x7E
#define ESC 0x7D
#define A_ER 0x03
#define A_RE 0x01
#define C_SET 0x03
#define C_DISC 0x0B
#define C_UA 0x07

typedef enum {
    LlTx, //transmissor
    LlRx, //recetor
} LinkLayerRole;

typedef struct {
    char serialPort[50];
    LinkLayerRole role;
    int baudRate;
    int nRetransmissions;
    int timeout;
} LinkLayer;

typedef enum {
    START,
    FLAG_RCV,
    A_RCV,
    C_RCV,
    BCC1_OK,
    STOP_R,
    DATA_FOUND_ESC,
    READING_DATA,
    DISCONNECTED,
    BCC2_OK
} LinkLayerState;

//Configures the serial port and basic initial project configurations
void config(LinkLayer connectionParameters);

int sendSupervisionFrame(int fd, unsigned char A, unsigned char C);

// Open a connection using the "port" parameters defined in struct linkLayer.
// Return "1" on success or "-1" on error.
int llopen(LinkLayer connectionParameters);

// Send data in buf with size bufSize.
// Return number of chars written, or "-1" on error.
int llwrite(const unsigned char *buf, int bufSize);

// Receive data in packet.
// Return number of chars read, or "-1" on error.
int llread(unsigned char *packet, int *sizeOfPacket);

// Close previously opened connection.
// if showStatistics == TRUE, link layer should print statistics in the console on close.
// Return "1" on success or "-1" on error.
int llclose(int showStatistics, LinkLayer connectionParameters, float runTime);

#endif // LINK_LAYER_H
