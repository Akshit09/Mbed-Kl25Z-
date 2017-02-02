#include "mbed.h"

BusOut led(LED1, LED2, LED3);
Serial pc(USBTX, USBRX);
float voteB=0;
float voteA=0;
float voteC=0;
float totalVotes=0.0;
char choice1,choice2;

void printInfo()
{
	pc.printf("Make Your Choice\n\rPress S to Start\n\rPress P to Stop\n\rPress O to continue\n\r");
	
}	
int main()
{
	pc.printf("Welcome Voter!\n\rPress S to Start");

	while(1)
	{
		choice1=pc.getc();
		switch (choice1){
			case 'S':
					printInfo();
			case 'O':
					pc.printf("Press A to vote AAP\n\rPress B to vote BJP\n\rPress C to vote Congress\n\r");
					break;
			case 'A':
							led=0x7;
							led=0x3;
							voteA++;
							totalVotes++;
							printInfo();
							break;
			case 'B':
							led=0x7;
							led=0x5;
							voteB++;
							totalVotes++;
							printInfo();
							break;
			case 'C':
							led=0x7;
							led=0x6;							
							voteC++;
							totalVotes++;
							printInfo();
							break;
		  case 'P':
							led=0x4;
							if((voteA>voteB)&&(voteA>voteC))
								pc.printf("AAP won:%0.2f\r\n",voteA/totalVotes);
							else if((voteB>voteA)&&(voteB>voteC))
								pc.printf("BJP won:%0.2f\r\n",voteB/totalVotes);
							else 
								pc.printf("Congress won:%0.2f\r\n",voteC/totalVotes);
	}
}

}	