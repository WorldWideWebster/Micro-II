/*
 * File: Building Linux Kernel and Controlling an I2C Device 
 * 
 * Authors: Munib Elkhatib, Sean Webster, Eric Craaybeek
 *
 * 11/14/2016
 *
 */

#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "cv.h"
#include "highgui.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>

#define BW_THRESHOLD  16

using namespace std;
using namespace cv;

//prototype functions
void TakePic(int i2, CvCapture* camera);
int GetTemp();

//var to protect from taking two pics in a row
int hasTaken = 0;

int main()
{
	//create var for camera
	CvCapture* capture = 0;

	//set camera var to any camera, set up camera dimensions
    capture = cvCaptureFromCAM( -1 ); //0=default, -1=any camera, 1..99=your camera
    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH, 640 ); //175
    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT, 480);//144
	
	//error detection
	if(!capture) cout << "No camera detected" << endl;
    if( capture )
	{
		int i=0;
		
		//start main loop
		while(1)
		{
		
			int temperature_flag;
			
			//if get temp returns 1, take picture
			temperature_flag = GetTemp();
			if(temperature_flag==1 && hasTaken ==0)
			{
				//take the picture and wait a few seconds
				hasTaken = 1;
				TakePic(i,capture);
				i++;
			
			}
		
		}
		
	}
		
}

//get temperature function
int GetTemp()
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
			return 1;
	}

	err = ioctl(fd, I2C_SLAVE, addr); // Set i2c device at addr as slave, return err as return code
	if(err < 0)
	{
			perror("Selecting i2c device\n");
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
			perror("reading i2c device\n");
		}
		usleep(delay);
	}
		
	//convert data to celcius		
	unsigned char MSB;
	unsigned char LSB;
	
	MSB = value[3];
	LSB = value[2];
	
	float temp = (MSB << 8 | LSB) >> 4;
	
	temp = temp*.0625;
	
	printf("The temperature is %.2f\n", temp);
			
	//close file	
	close(fd);
	
	usleep(500000);
	//return value used with take picture condition
	if (temp>=32)
		return 1;
	if (temp<32)
	{
		hasTaken=0;
		return 0;
		
	}


		
}


//take picture function
void TakePic(int i2, CvCapture* camera)
{
	
	int i = 0;
    
	printf("Taking Picture\n");
	
	//path to save picture	
	char path[100];
	sprintf(path,"/media/mmcblk0p1/project3/pic%d.jpg",i2);
		
	//loop for taking picture	
    while(i<5) {
         
        IplImage* picture = cvQueryFrame( camera ); //initialize image and take picture
        cvSaveImage( path , picture); //save image
        
		i++;
         
    }
	return;
}



