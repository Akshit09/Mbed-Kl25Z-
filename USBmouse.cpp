#include "mbed.h"
#include "USBMouse.h"
#include "MMA8451Q.h"
#include "TSISensor.h"
#define MMA8451_I2C_ADDRESS (0x1d<<1)
USBMouse mouse;
TSISensor tsi;
Serial pc(USBTX, USBRX);
MMA8451Q acc(PTE25,PTE24, MMA8451_I2C_ADDRESS);
int main()
{
	float click=0;
	float x=0;
	float y =0;
	char choice;
	
	while(1)
		{
			pc.printf("How fast you want to move :\nslow's' \nmedium'm' \nfast'f'\n\r");
		if(pc.readable())
			choice=pc.getc();
			switch(choice)
			{
				case's':
		x=-5*acc.getAccY();
		y=5*acc.getAccX();
			break;
				case'm':
		x=-10*acc.getAccY();
		y=10*acc.getAccX();
			break;
        case'f':
		x=-15*acc.getAccY();
		y=15*acc.getAccX();
			break;
				default:
					continue;
			}				
		mouse.move(x,y);
		click= tsi.readPercentage();
		if(click>0.60)
			mouse.press(MOUSE_LEFT);
		else 
			mouse.release(MOUSE_LEFT);
		if((click<0.40 && click>0))
			mouse.press(MOUSE_RIGHT);
		else 
			mouse.release(MOUSE_RIGHT);
		wait(0.001);
	}
}



