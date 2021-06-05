#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "HelloWorld.h"

void LCD_Testcase(void){

        HD44780_ClrScr();
        HD44780_Str_XY(0,3,"WELCOME TO");
        HD44780_Str_XY(1,0,"KERNEL MASTERS");
}


void KM_BBB_GPIO_Init(void)
{
        KM_GPIO_Export(44); // LCD_D4
        KM_GPIO_Direction(44,1);// Set output direction
	KM_GPIO_Export(45); // LCD_D5
        KM_GPIO_Direction(45,1);// Set output direction
	KM_GPIO_Export(46); // LCD_D6
	KM_GPIO_Direction(46,1);// Set output direction
	KM_GPIO_Export(47); // LCD_D7
        KM_GPIO_Direction(47,1);// Set output direction
	KM_GPIO_Export(86); // LCD_RS
	KM_GPIO_Direction(86,1);// Set output direction
	KM_GPIO_Export(87); // LCD_RW
        KM_GPIO_Direction(87,1);// Set output direction
	KM_GPIO_Export(88); // LCD_EN
        KM_GPIO_Direction(88,1);// Set output direction
	KM_GPIO_Export(9); // BUZZER
        KM_GPIO_Direction(9,1);// Set output direction
}

void KM_BBB_GPIO_Exit(void)
{
        KM_GPIO_Unexport(44);
	KM_GPIO_Unexport(45);
	KM_GPIO_Unexport(46);
	KM_GPIO_Unexport(47);
	KM_GPIO_Unexport(86);
	KM_GPIO_Unexport(87);
	KM_GPIO_Unexport(88);
	KM_GPIO_Unexport(9); // BUZZER
}

int main(int argc, char *argv[])
{
        KM_BBB_GPIO_Init();   //LCD, Buzzer Initalization
        KM_LCD_Init();
	KM_GPIO_Write(9,1); // BUZZER ON
        sleep(2);           // 2 sec delay
	KM_GPIO_Write(9,0); // BUZZER OFF
	LCD_Testcase();
        KM_BBB_GPIO_Exit();   //LCD, Buzzer Uninitalization

	return 0;
}
