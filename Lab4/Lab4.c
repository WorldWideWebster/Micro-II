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
/*int openGPIO(int gpio, int direction )
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
	sprintf(buffer, "%d", gpio);	
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
   	}
	// Direction = in
    	else
    	{
        	write(fileDirectory, "in", 2);
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
	if(direction == GPIO_DIRECTION_OUT)
	{
		write(fileDirectory, "strong", 6);
	}
	else
	{
		write(fileDirectory, "pulldown", 8);
	}
	close(fileDirectory);	

	
	
	//*********4.Open GPIO for Read / Write**********************
	sprintf(buffer, "/sys/class/gpio/gpio%d/value", gpio);
	fileDirectory = open(buffer, O_WRONLY);
	
	if(ERROR == fileDirectory)
	{
		   puts("Unable to open file:");
		   puts(buffer);
		   return(-1);
	
	}
	write(fileDirectory, "%d", fileMode);
	//Return memory address to use in other parts
	return fileDirectory;
	
}*/
//open GPIO and set the direction
void openGPIO(int gpio, int direction )
{		
        //  initialize character arrays for system commands and clear them
        char buf[4] = {}; // 4 = size of "out" plus '\0'
		memset(buf,0,sizeof(buf));
		char str_dir_set[50] = {};  // 50 = size of system() call
		memset(str_dir_set,0,sizeof(str_dir_set));
		
		// detect direction from input arguement
		if (direction == GPIO_DIRECTION_IN)
		{
			strcat(buf,"in");  
		}
		else if (direction == GPIO_DIRECTION_OUT)
		{
			strcat(buf,"out");
		}
		// switch on gpio and create direction system commands
		// direction is a file that contains a string that is either "out" or "in"
		switch(gpio)
		{
			case Strobe:
			sprintf(str_dir_set, "echo -n %s > /sys/class/gpio/gpio40/direction", buf);
			system(str_dir_set);
			case GP_4: // pin 4 requires a linux and level shifter GPIO
			sprintf(str_dir_set, "echo -n %s > /sys/class/gpio/gpio6/direction", buf);
			system(str_dir_set);
			sprintf(str_dir_set, "echo -n %s > /sys/class/gpio/gpio36/direction", buf);
			system(str_dir_set);
			case GP_5: // pin 5 requires a linux and level shifter GPIO
			sprintf(str_dir_set, "echo -n %s > /sys/class/gpio/gpio0/direction", buf);
			system(str_dir_set);
			sprintf(str_dir_set, "echo -n %s > /sys/class/gpio/gpio18/direction", buf);
			system(str_dir_set);
			case GP_6:  // pin 6 requires a linux and level shifter GPIO
			sprintf(str_dir_set, "echo -n %s > /sys/class/gpio/gpio1/direction", buf);
			system(str_dir_set);
			sprintf(str_dir_set, "echo -n %s > /sys/class/gpio/gpio20/direction", buf);
			system(str_dir_set);
			case GP_7:
			sprintf(str_dir_set, "echo -n %s > /sys/class/gpio/gpio38/direction", buf);
			system(str_dir_set);
		}
		
}


//****************OLD FUNCTION FROM LAB 2***************************
//write values GPIO
/*int writeGPIO(int fileDirectory, int value)
{
	// previous way: cat /sys/class/gpio/gpio40/value


	write(fileDirectory,value ,1);
	return 0;
}*/

//write value
void writeGPIO(int gpio, int value)
{
	// initialize system call string for setting the value
	// value is a file that contains a string that is either "0" or "1"
    char str_st1[50] = {};  // 50 = size of system() call
	memset(str_st1,0,sizeof(str_st1));
	
	// write the first portion of the value system() call
    if (value==HIGH) // if value is HIGH
    {
		strcat(str_st1,"echo -n \"1\" > /sys/class/gpio/");
    }
    else if (value==LOW) // if value is LOW
    {
		strcat(str_st1,"echo -n \"0\" > /sys/class/gpio/");
    }
	// switch on gpio and create value system commands
	// writing to the value file requires the Linux GPIO
    switch (gpio)
    {
		case Strobe:
		strcat(str_st1,"gpio40/value\n");
		system(str_st1);
		break;
        case GP_4:
        strcat(str_st1,"gpio6/value\n");
        system(str_st1);
        break;
        case GP_5:
        strcat(str_st1,"gpio0/value\n");
        system(str_st1);
        break;
        case GP_6:
        strcat(str_st1,"gpio1/value\n");
        system(str_st1);
        break;
        case GP_7:
        strcat(str_st1,"gpio38/value\n");
        system(str_st1);
        break;
    }
}

void send(int message)
{
	openGPIO(GP_4, GPIO_DIRECTION_OUT);
	openGPIO(GP_5, GPIO_DIRECTION_OUT);
	openGPIO(GP_6, GPIO_DIRECTION_OUT);
	openGPIO(GP_7, GPIO_DIRECTION_OUT);
	openGPIO(Strobe, GPIO_DIRECTION_OUT);
	// **************1.Strobe high*************************
	writeGPIO(GP_S, 1);
	// **************2.write data**************************
	writeGPIO(GP_4, (message && 0b0001));
	writeGPIO(GP_5, (message && 0b0010) >> 1);
	writeGPIO(GP_6, (message && 0b0100) >> 2);
	writeGPIO(GP_7, (message && 0b1000) >> 3);
	//***************3.Strobe low**************************
	writeGPIO(fileHandleGPIO_S, 0);
}
char receive(void)
{
	int message = 0;
	char currBit;
	openGPIO(Strobe, GPIO_DIRECTION_OUT);
	openGPIO(GP_4, GPIO_DIRECTION_IN);
	openGPIO(GP_5, GPIO_DIRECTION_IN);
	openGPIO(GP_6, GPIO_DIRECTION_IN);
	openGPIO(GP_7, GPIO_DIRECTION_IN);
	// **************1.Strobe high*************************
	writeGPIO(GP_S, 1);
	// **************2.read data***************************
	currBit = system("cat /sys/class/gpio/gpio6/value");
	message = message << 1;
	message |= currBit;
	currBit = system("cat /sys/class/gpio/gpio0/value");
	message = message << 1;
	message |= currBit;
	currBit = system("cat /sys/class/gpio/gpio1/value");
	message = message << 1;
	message |= currBit;
	currBit = system("cat /sys/class/gpio/gpio38/value");
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
















