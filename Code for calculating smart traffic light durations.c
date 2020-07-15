#include <reg52.h>
sbit r1=P2^0;
sbit y1=P2^1;
sbit g1=P2^2;

sbit r2=P2^3;
sbit y2=P2^4;
sbit g2=P2^5;

sbit r3=P2^6;
sbit y3=P2^7;
sbit g3=P3^4;

sbit r4=P3^5;
sbit y4=P3^6;
sbit g4=P3^7;

sbit s1=P3^0;
sbit s2=P3^1;
sbit s3=P3^2;
sbit s4=P3^3;

sfr dat=0x90;
void delay(unsigned int v)
{
  unsigned int j;
  for(;v>0;v--)
   for(j=0;j<230;j++);
}

void side1();
void side2();
void side3();
void side4();

unsigned int i;
unsigned char ch=0x00;
void main()
{
r1=r2=r3=r4=g1=g2=g3=g4=y1=y2=y3=y4=0;
delay(500);
r1=r2=r3=r4=g1=g2=g3=g4=y1=y2=y3=y4=1;
delay(500);
r1=r2=r3=r4=g1=g2=g3=g4=y1=y2=y3=y4=0;
delay(500);
r1=r2=r3=r4=g1=g2=g3=g4=y1=y2=y3=y4=1;
delay(500);
r1=1;r2=r3=r4=0;
g1=1;g4=g2=g3=1;
y1=0;y4=y2=y3=1;	
delay(500);
r1=1;r2=r3=r4=0;
g1=g4=g2=g3=1;
y1=0;y4=y2=y3=1;
delay(1000);	
while(1)
{
side1();
side2();
side3();
side4();
}
}
void side1()
{
ch=dat&0x03;
	switch(ch)
	{
		case 0x00:
									//str("side 1 level 1");
									s1=0;
                  g1=0;
				          y1=1;
				          r1=1;
		              r2=r3=r4=0;
						      g4=g2=g3=1;
						      y4=y2=y3=1;
                  
                     delay(5000);
                  g1=1;
									y1=0;
									r1=1;
									r2=r3=r4=0;
									g4=g2=g3=1;
									y4=y2=y3=1;
                  delay(2000);
									break;
		case 0x01:
									//str("side 1 level 2");
									s1=0;
                  g1=0;
				          y1=1;
				          r1=1;
		              r2=r3=r4=0;
						      g4=g2=g3=1;
						      y4=y2=y3=1;
                  for(i=0;i<10;i++)
                     delay(1000);
                  g1=1;
									y1=0;
									r1=1;
									r2=r3=r4=0;
									g4=g2=g3=1;
									y4=y2=y3=1;
                  delay(2000);
								  break;
		case 0x03:
                // str("side 1 level 3");
									s1=1;
									g1=0;
				          y1=1;
				          r1=1;
		              r2=r3=r4=0;
						      g4=g2=g3=1;
						      y4=y2=y3=1;
                  for(i=0;i<20;i++)
                     delay(1000);
                  g1=1;
									y1=0;
									r1=1;
									r2=r3=r4=0;
									g4=g2=g3=1;
									y4=y2=y3=1;
                  delay(2000);
								 break;
										}
				}

void side2()
{
	delay(100);
ch=dat&0x0c;
	switch(ch)
	{
		case 0x00:
									s2=0;
									//str("side 2 level 1");
                  g2=0;
				          y2=1;
				          r2=1;
		              r1=r3=r4=0;
						      g4=g1=g3=1;
						      y4=y1=y3=1;
                  for(i=0;i<5;i++)
                     delay(1000);
                  g2=1;
									y2=0;
									r2=1;
									r1=r3=r4=0;
									g4=g1=g3=1;
									y4=y1=y3=1;
                  delay(2000);
									break;
		case 0x04:
									s2=0;
                  //str("side 2 level 2");
									g2=0;
				          y2=1;
				          r2=1;
		              r1=r3=r4=0;
						      g4=g1=g3=1;
						      y4=y1=y3=1;
                  for(i=0;i<10;i++)
                     delay(1000);
                  g2=1;
									y2=0;
									r2=1;
									r1=r3=r4=0;
									g4=g1=g3=1;
									y4=y1=y3=1;
                  delay(2000);
									break;
		case 0x0C:
									s2=1;
                  //str("side 2 level 3");
									g2=0;
				          y2=1;
				          r2=1;
		              r1=r3=r4=0;
						      g4=g1=g3=1;
						      y4=y1=y3=1;
                  for(i=0;i<20;i++)
                     delay(1000);
                  g2=1;
									y2=0;
									r2=1;
									r1=r3=r4=0;
									g4=g1=g3=1;
									y4=y1=y3=1;
                  delay(2000);
									break;
				}
	}
	void side3()
{
	delay(100);
ch=(dat)&(0x30);
	switch(ch)
	{
		case 0x00:
    //str("side 3 level 1");   
									s3=0;
		              g3=0;
				          y3=1;
				          r3=1;
		              r2=r1=r4=0;
						      g4=g2=g1=1;
						      y4=y2=y1=1;
                  for(i=0;i<5;i++)
                     delay(1000);
                  g3=1;
									y3=0;
									r3=1;
									r2=r1=r4=0;
									g4=g2=g1=1;
									y4=y2=y1=1;
                  delay(2000);
									break;
		case 0x10:
		//	str("side 3 level 2");
									s3=0;
                  g3=0;
				          y3=1;
				          r3=1;
		              r2=r1=r4=0;
						      g4=g2=g1=1;
						      y4=y2=y1=1;
                  for(i=0;i<10;i++)
                     delay(1000);
                  g3=1;
									y3=0;
									r3=1;
									r2=r1=r4=0;
									g4=g2=g1=1;
									y4=y2=y1=1;
                  delay(2000);
									break;
		case 0x30:
			//str("side 3 level 3");
									s3=1;
                  g3=0;
				          y3=1;
				          r3=1;
		              r2=r1=r4=0;
						      g4=g2=g1=1;
						      y4=y2=y1=1;
                  for(i=0;i<20;i++)
                     delay(1000);
                  g3=1;
									y3=0;
									r3=1;
									r2=r1=r4=0;
									g4=g2=g1=1;
									y4=y2=y1=1;
                  delay(2000);
									break;
										}
				}
void side4()
{
ch=dat&0xc0;
	switch(ch)
	{
		case 0x00:
			//str("side 4 level 1");
									s4=0;
                  g4=0;
				          y4=1;
				          r4=1;
		              r2=r3=r1=0;
						      g1=g2=g3=1;
						      y1=y2=y3=1;
                  for(i=0;i<5;i++)
                     delay(1000);
                  g4=1;
									y4=0;
									r4=1;
									r2=r3=r1=0;
									g1=g2=g3=1;
									y1=y2=y3=1;
                  delay(2000);
									break;
		case 0x40:
		//	str("side 4 level 2");
									s4=0;
                  g4=0;
				          y4=1;
				          r4=1;
		              r2=r3=r1=0;
						      g1=g2=g3=1;
						      y1=y2=y3=1;
                  for(i=0;i<10;i++)
                     delay(1000);
                  g4=1;
									y4=0;
									r4=1;
									r2=r3=r1=0;
									g1=g2=g3=1;
									y1=y2=y3=1;
                  delay(2000);
									break;
		case 0xC0:
			//str("side 4 level 3");
									s4=1;
                  g4=0;
				          y4=1;
				          r4=1;
		              r2=r3=r1=0;
						      g1=g2=g3=1;
						      y1=y2=y3=1;
                  for(i=0;i<20;i++)
                     delay(1000);
                  g4=1;
									y4=0;
									r4=1;
									r2=r3=r1=0;
									g1=g2=g3=1;
									y1=y2=y3=1;
                  delay(2000);
									break;
										}
		}