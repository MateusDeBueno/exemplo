#include "peripheral_setup.h"

/**
 * main.c
 */

uint32_t count = 0;

int main(void)
{
    InitSysCtrl();                  //Initialize System Control
    DINT;                           //Disable CPU interrupts
    InitPieCtrl();                  //Initialize the PIE control register to their default state
    IER = 0x0000;                   //Disable CPU interrupts
    IFR = 0x0000;                   //Clear all CPU interrupt flags
    InitPieVectTable();             //Initialize the PIE vector table

    Setup_GPIO();

    EINT;                           //Enable Global interrupt INTM
    ERTM;                           //Enable Global realtime interrupt DBGM

    while(1){
        count++;
        if (count > 1000000){
            GpioDataRegs.GPASET.bit.GPIO31    =1;
            GpioDataRegs.GPBCLEAR.bit.GPIO34  =1;
        }
        else{
            GpioDataRegs.GPACLEAR.bit.GPIO31  =1;
            GpioDataRegs.GPBSET.bit.GPIO34    =1;

        }
        if (count>2000000)
            count=0;

    }
}
