#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


/* user commands */
#define MSG_RESET	0x0	// reset the sensor to the intitial state
#define MSG_PING	0x1	// check if the sensor is working properly
#define MSG_GET		0x2	// obtain the most recent ADC result

#define MSG_ACK		0xE	// ack message obtained from pic

#define LOW 0
#define HIGH 1

#define Strobe     (40) // IO8
#define GP_4       (6) // IO4
#define GP_5	   (0) // IO5
#define GP_6	   (1) // IO6
#define GP_7	   (38) // IO7
#define GPIO_DIRECTION_IN      (1)  
#define GPIO_DIRECTION_OUT     (0)
#define ERROR                  (-1)


void setGPIO(int, int);
void openGPIO(int, int);
void writeGPIO(int, int);
void send(int);
int receive(void);