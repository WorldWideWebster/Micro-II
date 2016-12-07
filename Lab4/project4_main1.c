/*
 * File: Multithreaded Programming and Image Processing
 * 
 * Authors: Munib Elkhatib, Sean Webster, Eric Craaybeek
 *
 * 12/5/2016
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <cstring>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "cv.h"
#include "highgui.h"
#include <curl/curl.h>
#include <sys/stat.h>

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

int index_counter = 0;

float GetTemp();
void TakePic();
void SendData();
void HTTP_POST(const char* url, const char* image, int size);
void setGPIO(int gpio, int direction );
int receive(void);
void send(int message);
void writeGPIO(int gpio, int value);
void openGPIO(int gpio, int direction );



char command[100];
int adc;


void *thread_command(void *arg);
void *thread_sensor(void *arg);
void *thread_communicate(void *arg);

char thread1[] = "Thread Command";
char thread2[] = "Thread Sensor";
char thread3[] = "Thread Communicate";

pthread_mutex_t mutx_command;
pthread_mutex_t mutx_adc;


// main() - just initializes the 3 threads
int main(int argc, char **argv)
{
	
	int i;
	void *thread_result;
	int state1,state2,state3;

	state1 = pthread_mutex_init(&mutx_command, NULL);
	state3 = pthread_mutex_init(&mutx_adc, NULL);

	if(state1||state3!=0)
		puts("Error mutex Initialization!!!");

	
	pthread_t t1, t2, t3;


	pthread_create(&t1, NULL, thread_command, &thread1);
	pthread_create(&t2, NULL, thread_sensor, &thread2);
	pthread_create(&t3, NULL, thread_communicate, &thread3);
	
	pthread_join(t1, &thread_result);	
	pthread_join(t2, &thread_result);
	pthread_join(t3, &thread_result);

	printf("All Terminated!\n");
	pthread_mutex_destroy(&mutx_command);
	pthread_mutex_destroy(&mutx_adc);
	return 0;
}

// thread_command() - thread handles UI
void *thread_command(void *arg)
{
	
	printf("Starting Thread: Command\n");
	
	//COMMAND INTERFACE HERE
	/*	this	thread	allows	for	local	user	commands	such	as	
	resetting	the	sensor,	checking	status,	setting	up	interrupts	and	reading	ADC	
	values.	This	thread	also	facilitates	debugging	the	program;*/
	
	while(1)
	{
		
		char cmd[100];
		printf("Enter the a command: ");
		fgets(cmd, 100, stdin);
		
		
		if (strncmp(cmd, "help", 4)==0)
		{
					
			printf("\nAvailable commands:\n");
			printf("reset - resets sensors\n");
			printf("status - checks the status of connected sensors\n");
			printf("readadc - reads data from ADC\n");
			printf("exit - exits this program\n\n");
					
		}
		
		if (strncmp(cmd, "status", 6)==0)
		{
			
			
			printf("Status Commmand Entered\n");
			pthread_mutex_lock(&mutx_command);
			strcpy (command, cmd);
			pthread_mutex_unlock(&mutx_command);
			
					
		}
		
		if (strncmp(cmd, "reset", 5)==0)
		{
					
			printf("Reset Commmand Entered\n");
			
			pthread_mutex_lock(&mutx_command);
			strcpy (command, cmd);
			pthread_mutex_unlock(&mutx_command);
			
					
		}
		
		
		if (strncmp(cmd, "readadc", 7)==0)
		{
					
			printf("Read ADC Commmand Entered\n");
			pthread_mutex_lock(&mutx_command);
			strcpy (command, cmd);
			pthread_mutex_unlock(&mutx_command);
			

			
		}
		
		if (strncmp(cmd, "exit", 4)==0)
		{
					
			printf("Exiting Program\n");
			return 0;
					
		}
		
		
			
	}
	
	
}

// thread_sensor() - thread handles communication with sensors
void *thread_sensor(void *arg)
{
	
	printf("Starting Thread: Sensor\n");
	
	//SENSOR CONTROL HERE
	/*this	thread	is	responsible	for	sending	commands	to	the	
	sensor	and	obtaining	sensor	responses. This	thread	also	needs	to	check	the	
	sensor’s status periodically	and	report	its	status	to	a	web	server (provided	by	
	the	instructor);*/
	
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
		
		if (GetTemp() > 32)
		{
			TakePic();
			printf("getting\n");
			msg = 0x2;
			send(msg);
			int i;
			value = 0;
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
			
			pthread_mutex_lock(&mutx_adc);
			adc = value;
			pthread_mutex_unlock(&mutx_adc);
			
			SendData();
			
			
		}
		
		printf("enter a command: ");
		scanf("%c", &cmd);

		pthread_mutex_lock(&mutx_command);
		if (strncmp(command, "reset", 5)==0)
		{
			pthread_mutex_unlock(&mutx_command);
			printf("resetting\n");
			msg = 0x0;
			send(msg);
			usleep(1000);
			if(receive() != MSG_ACK)
				printf("error: no ack\n");	
			else
				printf("ACK received!\n");
		}

		else if (strncmp(command, "status", 5)==0)
		{
			pthread_mutex_unlock(&mutx_command);
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
		}
		else if (strncmp(command, "readadc", 7)==0)
		{
			pthread_mutex_unlock(&mutx_command);
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
		}
		else
			pthread_mutex_unlock(&mutx_command);
	
	}
	return 0;
}
	
// thread_communicate() - thread handles communication with server
void *thread_communicate(void *arg)
{
	while(1) {
		
		pthread_mutex_lock(&mutx_command);
		if (strncmp(command, "send", 4)==0)
		{
			pthread_mutex_unlock(&mutx_command);
			printf("Sending Data in 5 seconds\n");
			sleep(5);
			printf("Sending Data\n");
			SendData();
		}
		else
			pthread_mutex_unlock(&mutx_command);
	}
	
}

// GetTemp() - initializes I2C temp sensor and returns temp value
float GetTemp()
{
	
	int i, err, fd;
	unsigned char command[2]; //i2c command
	unsigned char value[4];   //i2c return data
	useconds_t delay = 2000;

	//i2c address
	char *dev = "/dev/i2c-0";
	int addr = 0x48;
	
	fd = open(dev, O_RDWR ); //open file
	if(fd < 0)
	{
			perror("Opening i2c device node\n");
			return -1;
	}

	err = ioctl(fd, I2C_SLAVE, addr); // Set i2c device at addr as slave, return err as return code
	if(err < 0)
	{
			perror("Selecting i2c device\n");
			return -1;
	}
	
	for(i = 0; i < 4; i++)
	{
		command[0] = 0x40 | ((i + 1) & 0x03); // output enable | read input i
		command[1]++;
		err = write(fd, &command, 2);
		usleep(delay);
		// the read is always one step behind the selected input
		err = read(fd, &value[i], 1);
		if(err != 1)
		{
			perror("Reading i2c device\n");
			return -1;
		}
		usleep(delay);
	}
		
	//convert data to celsius		
	unsigned char MSB;
	unsigned char LSB;
	
	MSB = value[3];
	LSB = value[2];
	
	float temp = (MSB << 8 | LSB) >> 4;
	
	temp = temp*.0625;
	
	//close file	
	close(fd);
	
	usleep(500000);
	//return value used with take picture condition
	
	return temp;
		
}

// TakePic() - initializes camera and takes picture
void TakePic()
{
	//create var for camera
	CvCapture* capture = 0;

	//set camera var to any camera, set up camera dimensions
    capture = cvCaptureFromCAM( -1 ); //0=default, -1=any camera, 1..99=your camera
    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH, 640 ); //175
    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT, 480);//144
	
	
	int i = 0;
    
	printf("Taking Picture\n");
	
	//path to save picture	
	char path[100];
	sprintf(path,"/media/mmcblk0p1/Project4/picture.jpg");
		
	//loop for taking picture	
    while(i<5) 
	{
         
        IplImage* picture = cvQueryFrame( capture ); //initialize image and take picture
        cvSaveImage( path , picture); //save image
        
		i++;
         
    }
	return;
}


void HTTP_POST(const char* url, const char* image, int size){
	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
	if(curl){
		curl_easy_setopt(curl, CURLOPT_URL, url);
                curl_easy_setopt(curl, CURLOPT_POST, 1);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE,(long) size);
                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, image);
		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
      			fprintf(stderr, "curl_easy_perform() failed: %s\n",
              			curl_easy_strerror(res));
		curl_easy_cleanup(curl);
	}
}

void SendData()
{
	
	printf("Starting Thread: Communicate\n");
	
	const char* hostname="129.63.205.97";
	const int   port=8000;
	const int   id=1;
	const char* password="password";
	const char* name="8";
	
	//this value needs to be passed in from sean
	const int   adcval=123;
	
	const char* status="Very+good+thank+you";
	
	
	char timestamp = (unsigned)time(NULL);
	
	
	
	//this value needs to be passed in from eric
	const char* filename= "picture.jpg";

	char buf[1024];
	snprintf(buf, 1024, "http://%s:%d/update?id=%d&password=%s&name=%s&data=%d&status=%s&timestamp=%s&filename=%s",
			hostname,
			port,
			id,
			password,
			name,
			adcval,
			status,
            timestamp,
			filename);	
	
	FILE *fp;
	
	struct stat num;
	stat(filename, &num);
	int size = num.st_size;
	printf("\n\nImage size: %dB\n", size);	

	char *buffer = (char*)malloc(size);

	fp = fopen(filename,"rb");
	int n = fread(buffer, 1, size, fp);
	
	HTTP_POST(buf, buffer, size);
	
	fclose(fp);
	return; 
}

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
	char buff;
	char currBit;
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



