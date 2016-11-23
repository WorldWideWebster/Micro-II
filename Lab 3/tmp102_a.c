#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>


int main( int argc, char **argv )
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

        while(1)
        {
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
                printf("0x%02x 0x%02x\n", value[3], value[2]);	// Print values from i2c
        }

        close(file);
        return(0);
}