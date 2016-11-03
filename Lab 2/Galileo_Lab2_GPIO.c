/*
 * File:   PIC and Galileo communication          
 *         
 * 
 * simple Galileo program example
 * for UMass Lowell 16.480/552
 * 
 * Author: Roy
 *
 * Created on 2014/9/13
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

//open GPIO and set the direction
int openGPIO(int gpio, int direction )
{
	char buffer[256];
	int theFile;		// file location to be opened
	int fileMode;		// file mode
	
    // 1.set the GPIO
	
	// Open file to write GPIO being used
	theFile = open("/sys/class/gpio/export", O_WRONLY);		
	// Close and return error if error
	if(ERROR == theFile)
	{
		puts("Error opening /sys/class/gpio/export");
		return ERROR;
	}
	// Write GPIO ports to buffer
	sprintf(buffer, %d, gpio);	
	// write buffer to file	
	write(fileName, buffer, strlen(buffer));	
	close(fileName); 	

      	// 2.set the direction
        system("echo -n "out" > /sys/class/gpio/gpio40/direction"):
	system("echo -n "out" > /sys/class/gpio/gpio6/direction");
	system("echo -n "out" > /sys/class/gpio/gpio0/direction");
	system("echo -n "out" > /sys/class/gpio/gpio4/direction");
	system("echo -n "out" > /sys/class/gpio/gpio38/direction");    

	//3.set the voltage
	system("echo -n "strong" > /sys/class/gpio/gpio40/drive");
	system("echo -n "strong" > /sys/class/gpio/gpio6/drive");
	system("echo -n "strong" > /sys/class/gpio/gpio0/drive");
	system("echo -n "strong" > /sys/class/gpio/gpio4/drive");
	system("echo -n "strong" > /sys/class/gpio/gpio38/drive");
}

//write value
int writeGPIO(...)
{
        //... (default arguments as written by professor)
	cat /sys/class/gpio/gpio40/value
	cat /sys/class/gpio/gpio6/value
	cat /sys/class/gpio/gpio0/value
	cat /sys/class/gpio/gpio4/value
	cat /sys/class/gpio/gpio38/value

}

//main
int main(void)
{
 	  int fileHandleGPIO_4;
        int fileHandleGPIO_5;
        int fileHandleGPIO_6;
        int fileHandleGPIO_7;
	  int fileHandleGPIO_S; 
        fileHandleGPIO_4 = openGPIO(GP_4, GPIO_DIRECTION_OUT);
        fileHandleGPIO_5 = openGPIO(GP_5, GPIO_DIRECTION_OUT);
        fileHandleGPIO_6 = openGPIO(GP_6, GPIO_DIRECTION_OUT);
        fileHandleGPIO_7 = openGPIO(GP_7, GPIO_DIRECTION_OUT);
	  fileHandleGPIO_S = openGPIO(Strobe, GPIO_DIRECTION_OUT);
       
        while(1)

   {
               1.Strobe high
               2.write data
               3.Strobe low
	         4.Strobe high
        }
}

















