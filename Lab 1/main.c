/*
 * File:   main.c
 * Author: Eric Craaybeek, Munib Elkhatib, Sean Webster
 *
 * Created on September 21, 2016, 4:40 PM
 */

#define _XTAL_FREQ 500000

#include <xc.h>
#include <htc.h>

void main(void) {
    
    //set port B to outputs and bit 5 to digital
    TRISB = 0x00;
    ANSELBbits.ANSB5 = 0;
    
    //set port A to inputs and bit 1 to analog
    TRISA = 0xFF;
    ANSELAbits.ANSA0 = 1;
    
    //set up ADC    
    ADCON1 = 0b11110000;
    ADCON0 = 0b10010001;
    ADPCH = 0b00000000;
    ADREF = 0b00000000;
    
    
    //initialize working variable A
    int A = 0;
    
    
    while(1)
    {     
        
        //wait until ADC is finished        
        while (ADCON0bits.ADGO)
        {
                     
            __delay_ms(1);
         
        }    
        
        //put 10 digit output into A
        A = (ADRESH << 8);
        A = A + ADRESL;
        
        
        //conditional to turn on LED based on A
        if (A > 0b111)
        {
            LATBbits.LATB5 = 0;            
        }
        else
        {
            LATBbits.LATB5 = 1;
        }  
        
        //restart ADC
        ADCON0bits.ADGO = 1;
    }
    return;
}