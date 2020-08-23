#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "HelloWorld.h"

void LCD_Testcase(void){

        HD44780_ClrScr();
        HD44780_Str_XY(0,3,"WELCOME TO");
        HD44780_Str_XY(1,0,"KERNEL MASTERS");
}


void KM_BBB_GPIO_Init(void){

        KM_GPIO_Export(9); // BUZZER
        KM_GPIO_Direction(9,1);// Set output direction	

} 

int main(int argc, char *argv[])
{
        KM_BBB_GPIO_Init();   //Switches, LED, Buzzer Initalization
        KM_LCD_Init();
	LCD_Testcase();


  return 0;
}
