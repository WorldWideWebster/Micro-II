//test.c
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	char buff;
	FILE *output = popen("cat /sys/class/gpio/gpio38/value", "r");
	int x;
	buff = fgetc(output);
	x = atoi(&buff);
	printf("\n%d\n", x);
}