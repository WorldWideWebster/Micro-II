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

void TakePic(int i2, CvCapture* camera);
int GetTemp();

int main()
{
	CvCapture* capture = 0;

    capture = cvCaptureFromCAM( -1 ); //0=default, -1=any camera, 1..99=your camera
    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH, 640 ); //175
    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT, 480);//144
	
	if(!capture) cout << "No camera detected" << endl;
    if( capture )
	{
		int i=0;
		while(1)
		{
		
		if(GetTemp()==1)
		{
			TakePic(i,capture);
			sleep(2);
			
		}
		
		i++;	
		
		}
		
	}
		
}

int GetTemp()
{
	int i, err, file;
	unsigned char command[2];	// Command to send via i2c
	unsigned char value[4];		// Register for bit values
	useconds_t delay = 2000;	// Delay timer
	
	char *dev = "/dev/i2c-0";	// Address of i2c device
	int addr = 0x48;

	printf("Damnit Moe\n");		// Damnit moe

	file = open(dev, O_RDWR );	// Open i2c file
	if(file < 0)				// Error if not opened
	{
			perror("Opening i2c device node\n");
			return 1;
	}

	err = ioctl(file, I2C_SLAVE, addr);		// Set i2c device at addr as slave, return err as return code
	if(err < 0)
	{
			perror("Selecting i2c device\n");
	}

	
	for(i = 0; i < 4; i++)
	{
		command[0] = 0x40 | ((i + 1) & 0x03); 	// output enable | read input i
		command[1]++;
		err = write(file, &command, 2);			// Write commands to i2c file
		usleep(delay);
		// the read is always one step behind the selected input
		err = read(file, &value[i], 1);			// Read from i2c file
		if(err != 1)
		{
				perror("reading i2c device\n");
		}
		usleep(delay);
	}
		
	//printf("0x%02x 0x%02x 0x%02x 0x%02x\n", value[0], value[1], value[2], value[3]);
		
	unsigned char MSB;
	unsigned char LSB;
	
	MSB = value[3];
	LSB = value[2];
	
	int temp = (MSB << 8 | LSB) >> 4;
	temp = temp*.0625;
	
	printf("The temperature is %d\n", temp);
			
		
	close(file);
	
	if (temp>31)
		return 1;
	if (temp<31)
		return 0;
	
		
}



void TakePic(int i2, CvCapture* camera)
{
	
	int i = 0;
      
	char path[100];
	sprintf(path,"/media/mmcblk0p1/project3/pic%s.jpg",ctime(time(0));
		
		
    while(i<5) {
         
        IplImage* picture = cvQueryFrame( camera );
        cvSaveImage( path , picture);
        
		i++;
         
    }
	return;
}



