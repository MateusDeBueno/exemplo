/*
 * peripheral_setup.c
 *
 *  Created on: 21 de mar de 2021
 *      Author: Mateus
 */

#include "peripheral_setup.h"

void Setup_GPIO(void){
    EALLOW;
    //Table 8-7. GPIO Muxed Pins
    //explica qual a funcao que cada pino pode receber

    GpioCtrlRegs.GPAPUD.bit.GPIO2 = 1;          //Disable pull-up on GPIO2 (EPWM2a)
    GpioCtrlRegs.GPAPUD.bit.GPIO3 = 1;          //Disable pull-up on GPIO3 (EPWM2b)
    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1;         //Configure GPIO2 as EPWM2a
    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1;         //Configure GPIO3 as EPWM2b


    //Configure GPIO as output pin
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO0 = 1;          //Configure as output pin
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO1 = 1;          //Configure as output pin
    GpioCtrlRegs.GPACSEL1.bit.GPIO1 = GPIO_MUX_CPU2;   //GPIO1 is controlled by CPU2


    GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 0;        //Led blue
    GpioCtrlRegs.GPADIR.bit.GPIO31 = 1;         //Configure as output pin
    GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0;        //Led red
    GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;         //Configure as output pin

    EDIS;
}
