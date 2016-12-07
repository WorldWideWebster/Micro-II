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


//open GPIO and set the direction
void setGPIO(int gpio, int direction )
{
	char buffer[256];

    //*******************1.set the GPIO************************
	printf("thisworks1\n");
	sprintf(buffer, "echo -n \"%d\" > /sys/class/gpio/export", gpio);
	system(buffer);	
	usleep(10000);
	//********** 2.set the direction***************************
	printf("thisworks2\n");
	sprintf(buffer, "echo -n \"out\" > /sys/class/gpio/gpio%d/direction", gpio);
	system(buffer);
	usleep(10000);
	/*//**************3.set the voltage**************************
	printf("thisworks3\n");
	sprintf(buffer, "echo -n \"strong\" > /sys/class/gpio/gpio%d/drive", gpio);
	system(buffer);
	usleep(10000);*/
	//*********4.Open GPIO for Read / Write**********************
	printf("thisworks4\n");
	sprintf(buffer, "echo -n 1 > /sys/class/gpio/gpio%d/value", gpio);
	system(buffer);
	usleep(10000);
	
}

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
	// **************1a.Strobe Low*************************
	usleep(1000);
	writeGPIO(Strobe, 0);
	usleep(1000);
	// **************2.write data**************************	
	printf("message = %d\n", message);
	writeGPIO(GP_4, (message & 0b0001));
	usleep(1000);
	writeGPIO(GP_5, (message & 0b0010) >> 1);
	usleep(1000);
	writeGPIO(GP_6, (message & 0b0100) >> 2);
	usleep(1000);
	writeGPIO(GP_7, (message & 0b1000) >> 3);
	usleep(10000);
	// **************1.Strobe high*************************
	writeGPIO(Strobe, 1);
	usleep(1000);
	// **************1a.Strobe Low*************************
	writeGPIO(Strobe, 0);
	usleep(1000);
}
int receive(void)
{
	FILE *output;
	int message = 0;
	unsigned char buff;
	unsigned char currBit;
	openGPIO(Strobe, GPIO_DIRECTION_OUT);
	openGPIO(GP_4, GPIO_DIRECTION_IN);
	openGPIO(GP_5, GPIO_DIRECTION_IN);
	openGPIO(GP_6, GPIO_DIRECTION_IN);
	openGPIO(GP_7, GPIO_DIRECTION_IN);
	// **************1.Strobe high*************************
	usleep(1000);
	writeGPIO(Strobe, 1);
	usleep(10000);
	// **************2.read data***************************
	output = popen("cat /sys/class/gpio/gpio6/value", "r");
	system("cat /sys/class/gpio/gpio6/value");
	buff = fgetc(output);
	currBit = atoi(&buff);
	printf("CurrBit: %d\n", currBit);
	
	message |= currBit;
	usleep(1000);
	//pclose(output);
	output = popen("cat /sys/class/gpio/gpio0/value", "r");
	system("cat /sys/class/gpio/gpio0/value");
	buff = fgetc(output);
	currBit = atoi(&buff);
	printf("CurrBit: %d\n", currBit);
	
	message = message << 1;
	message |= currBit;
	usleep(1000);
	//pclose(output);
	output = popen("cat /sys/class/gpio/gpio1/value", "r");
	system("cat /sys/class/gpio/gpio1/value");
	buff = fgetc(output);
	currBit = atoi(&buff);
	printf("CurrBit: %d\n", currBit);
	
	message = message << 1;
	message |= currBit;
	//pclose(output);
	usleep(1000);
	output = popen("cat /sys/class/gpio/gpio38/value", "r");
	system("cat /sys/class/gpio/gpio38/value");
	buff = fgetc(output);
	currBit = atoi(&buff);
	printf("CurrBit: %d\n", currBit);
	
	message = message << 1;
	message |= currBit;
	//pclose(output);
	usleep(1000);
	
	//***************3.Strobe low**************************
	writeGPIO(Strobe, 0);
	usleep(1000);
	return message;
}

//main
int main(void)
{
	
	setGPIO(40, 1);
	setGPIO(6, 1);
	setGPIO(0, 1);
	setGPIO(38, 1);
	setGPIO(1, 1);
	setGPIO(20, 1);
	setGPIO(18, 1);
	setGPIO(36, 1);
	
	
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
			else
				printf("ACK received!\n");
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
			else
				printf("ACK received!\n");
			break;
		case 'g' :
			printf("getting\n");
			msg = 0x2;
			send(msg);
			int i;
			value = 0;
			if(receive() != MSG_ACK)
			{
				printf("error: no ack\n");
				break;
			}
			else
				printf("ACK received!\n");
			for(i = 0; i < 3; i++)
			{
				usleep(1000);
				temp = receive();
				if(i == 0)
					value = (temp & 0b11) << 2;
				else
				{
					value = value << 4;
					value |= temp;
				}
			}
			printf("Value: %d\n", value);
			usleep(1000);
			
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
















