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





int index_counter = 0;

float GetTemp();
void TakePic();

char command[100];

void *thread_command(void *arg);
void *thread_sensor(void *arg);
void *thread_communicate(void *arg);

char thread1[] = "Thread Command";
char thread2[] = "Thread Sensor";
char thread3[] = "Thread Communicate";

pthread_mutex_t mutx;


// main() - just initializes the 3 threads
int main(int argc, char **argv)
{
	setGPIO(40, 1);
	setGPIO(6, 1);
	setGPIO(0, 1);
	setGPIO(38, 1);
	setGPIO(1, 1);
	setGPIO(20, 1);
	setGPIO(18, 1);
	setGPIO(36, 1);
	
	
	int i;
	void *thread_result;
	int state1;

	state1 = pthread_mutex_init(&mutx, NULL);

	if(state1!=0)
		puts("Error mutex Initialization!!!");

	
	pthread_t t1, t2, t3;


	pthread_create(&t1, NULL, thread_command, &thread1);
	pthread_create(&t2, NULL, thread_sensor, &thread2);
	pthread_create(&t3, NULL, thread_communicate, &thread3);
	
	pthread_join(t1, &thread_result);	
	pthread_join(t2, &thread_result);
	pthread_join(t3, &thread_result);

	printf("All Terminated!\n");
	pthread_mutex_destroy(&mutx);
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
		int value;
		unsigned char msg;
		unsigned char temp;
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
			printf("pinging\n");
			msg = 0x1;
			send(msg);
			sleep(1);
			temp = receive();
			printf("response: %x\n", temp);
			if(temp != MSG_ACK)
				printf("error: no ack\n")
			
			printf("Status Commmand Entered\n");
			/*pthread_mutex_lock(&mutx);
			strcpy (command, cmd);
			pthread_mutex_unlock(&mutx);
			*/
					
		}
		
		if (strncmp(cmd, "reset", 5)==0)
		{
					
			printf("Reset Commmand Entered\n");
			printf("resetting\n");
			msg = 0x0;
			send(msg);
			usleep(1000);
			if(receive() != MSG_ACK)
				printf("error: no ack\n");
			TakePic();

			
					
		}
		
		
		if (strncmp(cmd, "readadc", 7)==0)
		{
					
			printf("Read ADC Commmand Entered\n");
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
	
}

// thread_communicate() - thread handles communication with server
void *thread_communicate(void *arg)
{
	
	printf("Starting Thread: Communicate\n");
	
	//COMMUNICATION THREAD HERE
	/*this	thread	communicates	with	the	provided	web	server	
	using	HTTP	protocol	and	libcurl library. The	web	based communication	
	protocol	is	defined	in	Section	2.
	
	const char* hostname="kew.uml.edu";
	const int   port=8000;
	const int   id=8;
	const char* password="password123";
	const char* name="Team+Awesome";
	const int   adcval=123;
	const char* status="Very+good+thank+you";
	const char* timestamp="20141116-09:12:34";
	const char* filename="smile.jpg";

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
	printf("Image size: %dB\n", size);	

	char *buffer = (char*)malloc(size);

	fp = fopen(filename,"rb");
	int n = fread(buffer, 1, size, fp);

	HTTP_POST(buf, buffer, size);
	fclose(fp);
	return 0;*/
	
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
	
	int timestamp = (unsigned)time(NULL);
	int i = 0;
    
	printf("Taking Picture\n");
	
	//path to save picture	
	char path[100];
	sprintf(path,"/media/mmcblk0p1/Project4/pic%d.jpg",timestamp);
		
	//loop for taking picture	
    while(i<5) 
	{
         
        IplImage* picture = cvQueryFrame( capture ); //initialize image and take picture
        cvSaveImage( path , picture); //save image
        
		i++;
         
    }
	return;
}

/*
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
*/
