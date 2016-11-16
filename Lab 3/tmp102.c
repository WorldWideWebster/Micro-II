/*
    TMP Test Code
	5-31-10
    Copyright Spark Fun Electronics© 2010
    Nathan Seidle
	
	Example code for the TMP102 11-bit I2C temperature sensor
	
	You will need to connect the ADR0 pin to one of four places. This code assumes ADR0 is tied to VCC. 
	This results in an I2C address of 0x93 for read, and 0x92 for write.
	
	This code assumes regular 12 bit readings. If you want the extended mode for higher temperatures, the code
	will have to be modified slightly.

*/
#include <stdio.h>
#include <avr/io.h>
#include "i2c.h" //Needed  for I2C sensors

#define FALSE	0
#define TRUE	-1

#define FOSC 16000000 //16MHz external osc

#define SERIAL_BAUD 9600
#define SERIAL_MYUBRR (((((FOSC * 10) / (16L * SERIAL_BAUD)) + 5) / 10) - 1)

//Function definitions
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
void ioinit(void);
void delay_ms(uint16_t x);
void delay_us(uint16_t x);
int uart_putchar(char c, FILE *stream);

int16_t tmp102Read(void);

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

//Global variables
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

#define TMP_RD	 	0x93
#define TMP_WR	 	0x92 //Assume ADR0 is tied to VCC
#define TEMP_REG 	0x00

int main (void)
{
	int16_t temperature = 0;

    ioinit(); //Boot up defaults

	printf("TMP102 Example\n");

	while(1)
	{
		temperature = tmp102Read();
		printf("temperature = %dC\n", temperature);

		if ((UCSR0A & _BV(RXC0))) //Check for incoming RX characters
			if(UDR0 == 'x') break;
			
		delay_ms(500); //4Hz readings by default
		
		PORTB ^= (1<<5); //Toggle status LED
	}
	
	printf("You've gone too far!");
	while(1);

    return(0);
}

//Read a tmp102 sensor on a given temp_number or channel
int16_t tmp102Read(void)
{

	uint8_t msb, lsb;
	int16_t temp;
	
	i2cSendStart();	
    i2cWaitForComplete();
	
	i2cSendByte(TMP_WR); //We want to write a value to the TMP
	i2cWaitForComplete();

	i2cSendByte(TEMP_REG); //Set pointer regster to temperature register (it's already there by default, but you never know)
	i2cWaitForComplete();
	
	i2cSendStart();
	
	i2cSendByte(TMP_RD); // Read from this I2C address, R/*W Set
	i2cWaitForComplete();
	
	i2cReceiveByte(TRUE);
	i2cWaitForComplete();
	msb = i2cGetReceivedByte(); //Read the MSB data
	i2cWaitForComplete();

	i2cReceiveByte(FALSE);
	i2cWaitForComplete();
	lsb = i2cGetReceivedByte(); //Read the LSB data
	i2cWaitForComplete();
	
	i2cSendStop();
	
	//printf("0x%02X ", msb);
	//printf("0x%02X ", lsb);
	
	//Test
	//msb = 0b11100111;
	//lsb = 0b00000000; //From the datasheet, -25C
	
	temp = (msb<<8) | lsb;
	temp >>= 4; //The TMP102 temperature registers are left justified, correctly right justify them
	
	//The tmp102 does twos compliment but has the negative bit in the wrong spot, so test for it and correct if needed
	if(temp & (1<<11))
		temp |= 0xF800; //Set bits 11 to 15 to 1s to get this reading into real twos compliment

	//printf("%02d\n", temp);

	//But if we want, we can convert this directly to a celsius temp reading
	//temp *= 0.0625; //This is the same as a divide by 16
	//temp >>= 4; //Which is really just a shift of 4 so it's much faster and doesn't require floating point
	//Shifts may not work with signed ints (negative temperatures). Let's do a divide instead
	temp /= 16;

	return(temp);
}

void ioinit(void)
{
	//1 = output, 0 = input 
    DDRB = 0b11111111;
    DDRC = 0b11111111;
    DDRD = 0b11111111;

	PORTC = 0b00110000; //pullups on the I2C bus
	
    //Init Timer0 for delay_us
	TCCR0B = (1<<CS01); //Set Prescaler to clk/8 : 1click = 0.5us(assume we are running at external 16MHz). CS01=1 

    //Setup USART baud rate
    UBRR0H = SERIAL_MYUBRR >> 8;
    UBRR0L = SERIAL_MYUBRR;
    UCSR0B = (1<<RXEN0)|(1<<TXEN0); //No receive interrupt
	UCSR0A &= ~(1<<U2X0); //This clears the double speed UART transmission that may be set by the Arduino bootloader

    stdout = &mystdout; //Required for printf init
}

//General short delays
void delay_ms(uint16_t x)
{
	for (; x > 0 ; x--)
	{
		delay_us(250);
		delay_us(250);
		delay_us(250);
		delay_us(250);
	}
}

//General short delays
void delay_us(uint16_t x)
{
	x *= 2; //Runs at 16MHz instead of normal 8MHz

	while(x > 256)
	{
		TIFR0 = (1<<TOV0); //Clear any interrupt flags on Timer2
		TCNT0 = 0; //256 - 125 = 131 : Preload timer 2 for x clicks. Should be 1us per click
		while( (TIFR0 & (1<<TOV0)) == 0);
		
		x -= 256;
	}

	TIFR0 = (1<<TOV0); //Clear any interrupt flags on Timer2
	TCNT0 = 256 - x; //256 - 125 = 131 : Preload timer 2 for x clicks. Should be 1us per click
	while( (TIFR0 & (1<<TOV0)) == 0);
}

int uart_putchar(char c, FILE *stream)
{
    if (c == '\n') uart_putchar('\r', stream);
  
    loop_until_bit_is_set(UCSR0A, UDRE0);
    UDR0 = c;

    return 0;
}
