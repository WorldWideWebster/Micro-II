	/*
 * File:   PIC and Galileo communication          
 *         
 * 
 * simple Galileo program example
 * for UMass Lowell 16.480/552
 * 
 * Author: Sean Webster,Eric Craaybeek, Munib Elkhatib
 *
 * Created on 2014/9/13
 * Code from class example and from black-swift.com used
 */

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


#define Strobe     (40) // IO8
#define GP_4       (6) // IO4
#define GP_5	   (0) // IO5
#define GP_6	   (4) // IO6
#define GP_7	   (38) // IO7
#define GPIO_DIRECTION_IN      (1)  
#define GPIO_DIRECTION_OUT     (0)
#define ERROR                  (-1)

int main(void)
{
	int direction = 0;
	int gpio = 40;
	char buffer[256];
	int fileDirectory = 0;		// file location to be opened
	int fileMode = 1;		// file mode
	
    	//*******************1.set the GPIO************************
	// system command example:
	// system("echo -n "27" > /sys/class/gpio/export");
	
	// Open file to write GPIO being used
	fileDirectory = open("/sys/class/gpio/export", O_WRONLY);		
	sprintf(buffer, "%d", gpio);	
	write(fileDirectory, buffer, strlen(buffer));	
	close(fileDirectory); 	

    	//********** 2.set the direction***************************
	// system command example:
	// system("echo -n "out" > /sys/class/gpio/gpio6/direction");
	
    sprintf(buffer, "/sys/class/gpio/gpio%d/direction", gpio);
   	fileDirectory = open(buffer, O_WRONLY);

	// Direction = out
   	if (direction == GPIO_DIRECTION_OUT)
    {
       	write(fileDirectory, "out", 3);
		fileMode = O_WRONLY;
   	}
	// Direction = in
    else
   	{
        write(fileDirectory, "in", 2);
		fileMode = O_WRONLY;
   	}
   	close(fileDirectory);


	//**************3.set the voltage**************************
	// system command example:
	// system("echo -n "strong" > /sys/class/gpio/gpio40/drive");

    sprintf(buffer, "/sys/class/gpio/gpio%d/drive", gpio);
   	fileDirectory = open(buffer, O_WRONLY);
	write(fileDirectory, "strong", 6);
	close(fileDirectory);	

	
	
	//*********4.Open GPIO for Read / Write**********************
	sprintf(buffer, "/sys/class/gpio/gpio%d/value", gpio);
	fileDirectory = open(buffer, O_WRONLY);
	write(fileDirectory, "%d", fileMode);
	close(fileDirectory);
	//Return memory address to use in other parts
	return 0;
}