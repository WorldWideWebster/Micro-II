/*
 * File:   PIC and Galileo communication          
 *         
 * 
 * simple Galileo program example
 * for UMass Lowell 16.480/552
 * 
 * Author: Sean Webster
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


#define Strobe     (40) // IO8
#define GP_4       (6) // IO4
#define GP_5	   (0) // IO5
#define GP_6	   (4) // IO6
#define GP_7	   (38) // IO7
#define GPIO_DIRECTION_IN      (1)  
#define GPIO_DIRECTION_OUT     (0)
#define ERROR                  (-1)

int fileHandleGPIO_4;
int fileHandleGPIO_5;
int fileHandleGPIO_6;
int fileHandleGPIO_7;
int fileHandleGPIO_S;

//open GPIO and set the direction
int openGPIO(int gpio, int direction )
{
	char buffer[256];
	int fileDirectory;		// file location to be opened
	int fileMode;		// file mode
	
    //*******************1.set the GPIO************************
	// system command example:
	// system("echo -n "27" > /sys/class/gpio/export");
	
	// Open file to write GPIO being used
	fileDirectory = open("/sys/class/gpio/export", O_WRONLY);		
	// Close and return error if error
	if(ERROR == fileDirectory)
	{
		puts("Error opening /sys/class/gpio/export");
		return ERROR;
	}
	// Write GPIO ports to buffer
	sprintf(buffer, %d, gpio);	
	// write buffer to file	
	write(fileDirectory, buffer, strlen(buffer));	
	close(fileDirectory); 	

    //********** 2.set the direction***************************
	// system command example:
	// system("echo -n "out" > /sys/class/gpio/gpio6/direction");
	
    sprintf(buffer, "/sys/class/gpio/gpio%d/direction", gpio);
    fileDirectory = open(buffer, O_WRONLY);
	if(ERROR == fileDirectory)
	{
		puts("Unable to open file:");
		puts(buffer);
		return ERROR;
	}
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
	if(ERROR == fileDirectory)
	{
		puts("Unable to open file:");
		puts(buffer);
		return ERROR;
	}

    write(fileDirectory, "strong", 5);
	fileMode = O_WRONLY;
    close(fileDirectory);	

	
	
	//*********4.Open GPIO for Read / Write**********************
	sprintf(buffer, "/sys/class/gpio/gpio%d/value", gpio);
	fileDirectory = open(buffer, fileMode);
	if(ERROR == fileDirectory)
	{
		   puts("Unable to open file:");
		   puts(buffer);
		   return(-1);
	}
	//Return memory address to use in other parts
	return fileDirectory;
	
}

int readGPIO (int fileDirectory)
{
		char value;

        read(fileDirectory, &value, 1);

        return atoi(value);
}
//write values GPIO
int writeGPIO(int fileDirectory, int value)
{
	// previous way: cat /sys/class/gpio/gpio40/value
	write(fileDirectory, itoa(value), 1);
	return 0;
}

void send()
{
	fileHandleGPIO_4 = openGPIO(GP_4, GPIO_DIRECTION_OUT);
	fileHandleGPIO_5 = openGPIO(GP_5, GPIO_DIRECTION_OUT);
	fileHandleGPIO_6 = openGPIO(GP_6, GPIO_DIRECTION_OUT);
	fileHandleGPIO_7 = openGPIO(GP_7, GPIO_DIRECTION_OUT);
	fileHandleGPIO_S = openGPIO(Strobe, GPIO_DIRECTION_OUT);
	// **************1.Strobe high*************************
	writeGPIO(fileHandleGPIO_S, 1);
	// **************2.write data**************************

			3.Strobe low
	         4.Strobe high
}

//main
int main(void)
{
	int value;
	unsigned char bit[4];

	while(1)
	{
	char cmd;
	int msg;

	printf("enter a command: ");
	scanf("%c", &cmd);

	switch (cmd) {

	case 'r' :
		printf("resetting\n");
		msg = 0x0;
		break;
	case 'p' :
		printf("pinging\n");
		msg = 0x1;
		break;
	case 'g' :
		printf("getting\n");
		msg = 0x2;
		break;
	default : printf("command not recognized\n");
	}
}

















