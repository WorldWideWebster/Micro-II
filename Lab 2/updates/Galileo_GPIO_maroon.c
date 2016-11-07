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
	system("echo -n %d > /sys/class/gpio/export",gpio);
	
	/*
	// Open file to write GPIO being used
	fileDirectory = open("/sys/class/gpio/export", O_WRONLY);		
	// Close and return error if error
	if(ERROR == fileDirectory)
	{
		puts("Error opening /sys/class/gpio/export");
		return ERROR;
	}
	// Write GPIO ports to buffer
	sprintf(buffer, "%d", gpio);	
	// write buffer to file	
	write(fileDirectory, buffer, strlen(buffer));	
	close(fileDirectory); 	
	*/

    	//********** 2.set the direction***************************
	// system command example:

	system("echo -n %d > /sys/class/gpio/gpio%d/direction",direction,gpio);
	
    	/*sprintf(buffer, "/sys/class/gpio/gpio%d/direction", gpio);
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
	*/

	//**************3.set the voltage**************************
	// system command example:
	system("echo -n "strong" > /sys/class/gpio/gpio%d/drive",gpio);

	/*    	sprintf(buffer, "/sys/class/gpio/gpio%d/drive", gpio);
   	fileDirectory = open(buffer, O_WRONLY);
	if(ERROR == fileDirectory)
	{
		puts("Unable to open file:");
		puts(buffer);
		return ERROR;
	}
	if(direction == GPIO_DIRECTION_OUT)
	{
		write(fileDirectory, "strong", 6);
		fileMode = O_WRONLY;
	}
	else
	{
		write(fileDirectory, "pulldown", 8);
		fileMode = O_WRONLY;
	}
	close(fileDirectory);	

	
	*/	
	//*********4.Open GPIO for Read / Write**********************
	
	system("echo "1" > /sys/class/gpio/gpio%d/value", gpio);	

	/*
	sprintf(buffer, "/sys/class/gpio/gpio%d/value", gpio);
	fileDirectory = open(buffer, fileMode);
	if(ERROR == fileDirectory)
	{
		   puts("Unable to open file:");
		   puts(buffer);
		   return(-1);
	
	}
	*/	

	//Return memory address to use in other parts
	return fileDirectory;
	
}

int readGPIO (int fileDirectory, char value, int size)
{


        read(fileDirectory, value, size);

	int temp = value - '0';
	return temp;
}
//write values GPIO
int writeGPIO(int fileDirectory, int value)
{
	// previous way: cat /sys/class/gpio/gpio40/value


	write(fileDirectory,value ,1);
	return 0;
}

void send(int message)
{
	fileHandleGPIO_4 = openGPIO(GP_4, GPIO_DIRECTION_OUT);
	fileHandleGPIO_5 = openGPIO(GP_5, GPIO_DIRECTION_OUT);
	fileHandleGPIO_6 = openGPIO(GP_6, GPIO_DIRECTION_OUT);
	fileHandleGPIO_7 = openGPIO(GP_7, GPIO_DIRECTION_OUT);
	fileHandleGPIO_S = openGPIO(Strobe, GPIO_DIRECTION_OUT);
	// **************1.Strobe high*************************
	writeGPIO(fileHandleGPIO_S, 1);
	// **************2.write data**************************
	writeGPIO(fileHandleGPIO_4, (message && 0b0001));
	writeGPIO(fileHandleGPIO_5, (message && 0b0010) >> 1);
	writeGPIO(fileHandleGPIO_6, (message && 0b0100) >> 2);
	writeGPIO(fileHandleGPIO_7, (message && 0b1000) >> 3);
	//***************3.Strobe low**************************
	writeGPIO(fileHandleGPIO_S, 0);
}
char receive(void)

{
	int message = 0;
	char currBit;
	fileHandleGPIO_S = openGPIO(Strobe, GPIO_DIRECTION_OUT);
	fileHandleGPIO_4 = openGPIO(GP_4, GPIO_DIRECTION_IN);
	fileHandleGPIO_5 = openGPIO(GP_5, GPIO_DIRECTION_IN);
	fileHandleGPIO_6 = openGPIO(GP_6, GPIO_DIRECTION_IN);
	fileHandleGPIO_7 = openGPIO(GP_7, GPIO_DIRECTION_IN);
	// **************1.Strobe high*************************
	writeGPIO(fileHandleGPIO_S, 1);
	// **************2.read data***************************
	readGPIO(fileHandleGPIO_4, currBit, 1);
	message = message << 1;
	message |= currBit;
	readGPIO(fileHandleGPIO_5, currBit, 1);
	message = message << 1;
	message |= currBit;
	readGPIO(fileHandleGPIO_6, currBit, 1);
	message = message << 1;
	message |= currBit;
	readGPIO(fileHandleGPIO_7, currBit, 1);
	message = message << 1;
	message |= currBit;
	
	//***************3.Strobe low**************************
	writeGPIO(fileHandleGPIO_S, 0);
	return message;
}

//main
int main(void)
{
	
	int value;
	unsigned char msg;
	unsigned char temp;
	char cmd;
	
	while(1)
	{
		printf("enter a command: ");
		scanf("%c", &cmd);

		switch (cmd) {

		case 'r' :
			printf("resetting\n");
			msg = 0x0;
			send(msg);
			usleep(1000);
			if(receive() != MSG_ACK)

				printf("error: no ack\n");
			break;
		case 'p' :
			printf("pinging\n");
			msg = 0x1;
			send(msg);
			sleep(1);
			temp = receive();
			printf("response: %x\n", temp);
			if(temp != MSG_ACK)
				printf("error: no ack\n");
			break;
		case 'g' :
			printf("getting\n");
			msg = 0x2;
			send(msg);
			int i;
			for(i = 0; i < 3; i++)
			{
				usleep(1000);
				temp = receive();
				value = value << 4;
				value |= temp;
			}
			usleep(1000);
			if(receive() != MSG_ACK)
				printf("error: no ack\n");
			break;
			break;
		case 'q' :
			printf("quitting\n");
			return;
		default : printf("command not recognized\n");
		}

	
	}
	return 0;
}

















