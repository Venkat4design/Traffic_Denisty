#include <reg52.H>
sbit rs=P3^5;
sbit rw=P3^6;
sbit en=P3^7;

sbit s1=P1^0;	   
sbit s2=P1^1;	   
sbit s3=P1^2;	   
sbit s4=P1^3;
void send(unsigned char *id,unsigned int c);

unsigned int h1,t1,h2,t2,cs;
code unsigned char id1[]="5d01e707c03f977f534e0567";
code unsigned char id2[]="5d01e732c03f9701429b23e2";
code unsigned char id3[]="5d01e71dc03f977ff8183d76";
code unsigned char id4[]="5d01e71dc03f977ff8183d76";
void delay(unsigned int i)
{
unsigned int j;
for(;i>0;i--)
for(j=0;j<122;j++);
}
void lcdcmd(unsigned char x)
{
P2=x;
rs=0;
rw=0;
en=1;
delay(10);
en=0;
delay(10);
}
void cmd(unsigned char x)
{
P2=x;
rs=0;
rw=0;
en=1;
delay(10);
en=0;
delay(10);
}
void lcddisp(unsigned char x)
{
P2=x;
rs=1;
rw=0;
en=1;
delay(10);
en=0;
delay(10);
}
void lcddisplay(unsigned char *m)
{
while(*m)
lcddisp(*m++);
}

void tx(unsigned char x)
{
SBUF=x;
while(TI==0);
TI=0;
}
unsigned char rx()
{
while(RI==0);
RI=0;
return SBUF;
}
void tx_str(unsigned char *m)
{
while(*m)
tx(*m++);
}
void txstr(unsigned char *m)
{
while(*m)
tx(*m++);
}

void send(unsigned char *id,unsigned int c)
{
 unsigned char ch;
l: 
 	lcdcmd(0x8a);
	lcddisplay("SEND");
	ch=0;
	delay(2000);
 	tx_str("AT+CIPSTART=\"TCP\",\"things.ubidots.com\",80");
	tx(0x0D);
	tx(0x0A);
	while(ch != 'L' && ch != 'D')
	ch=rx();
	if(ch=='L')
	{
	lcdcmd(0x8a);
	lcddisplay("LINK ");
	delay(2000);
	tx_str("AT+CIPMODE=0");
	tx(0x0D);
	tx(0x0A);
	delay(3000);
	tx_str("AT+CIPSEND=");
	tx_str("209");
	tx(0x0D);
	tx(0x0A);
	while(rx() != '>');
	delay(3000);
		lcdcmd(0x8a);
	lcddisplay("UPLD ");
	
tx_str("POST /api/v1.6/variables/");
while(*id)
tx(*id++);
tx_str("/values HTTP/1.1");
tx(0x0D);
tx(0x0A);
tx_str("Content-Type: application/json");
tx(0x0D);
tx(0x0A);
tx_str("Content-Length: ");	 //11+no.of digits(1,2,3,4)
tx_str("12");              //12 for digital signal value send like 1 or 0 (1 digit )of sensor value 15 for analog value(4 digit)
tx(0x0D);
tx(0x0A);

tx_str("X-Auth-Token: A1E-HqypKXzh9eude1Zdu2J5ycKHTerkgj");// after colomn space is necessaRY
tx(0x0D);             
tx(0x0A);
tx_str("Host: things.ubidots.com");
tx(0x0D);
tx(0x0A);

tx(0x0D);
tx(0x0A);
tx_str("{\"value\": ");   // content length value
tx(c+48);
tx('}');
tx(0x0D);
tx(0x0A);
tx(0x0D);
tx(0x0A);
while(rx() != '}');
while(rx() != '}');

lcdcmd(0x01);
delay(4000);
 lcdcmd(0x8a);
	lcddisplay("CLOSE");

tx_str("AT+CIPCLOSE");
tx(0x0D);
tx(0x0A);
	delay(2000);

}

else {
	lcdcmd(0x8a);
	lcddisplay("ERROR");
		delay(2000);
		goto l;
		}

}

void main()
{
unsigned char i,ip[10];
SCON=0X50;
TMOD=0X20;
TH1=0XFD;
TR1=1;
lcdcmd(0x38);
lcdcmd(0x80);
lcdcmd(0x01);
lcdcmd(0x06);
lcdcmd(0x0e);

lcdcmd(0x80);
lcddisplay("IOT BSD DENSITY");
lcdcmd(0xc0);
lcddisplay("ANALYSER SYSTEM");
delay(2000);
lcdcmd(0x01);
lcdcmd(0x80);
lcddisplay("AT");
txstr("AT");
tx(0x0d);
tx(0x0a);
delay(2000);

lcdcmd(0x80);
lcddisplay("AT+RST");
txstr("AT+RST");
tx(0x0d);
tx(0x0a);
delay(2000);

lcdcmd(0x80);
lcddisplay("AT+CWMODE=1");
txstr("AT+CWMODE=1");
tx(0x0d);
tx(0x0a);
delay(2000);

lcdcmd(0x80);
lcddisplay("AT+CIFSR");
txstr("AT+CIFSR");
tx(0x0d);
tx(0x0a);
while(rx()!='.');
for(i=0;i<8;i++)
ip[i]=rx();
lcdcmd(0x01);
lcdcmd(0x80);
lcddisplay("192.");
for(i=0;i<8;i++)
lcddisp(ip[i]);
delay(1000);
lcdcmd(0x01);
lcdcmd(0x80);
lcddisplay("AT+CWMODE=3");
txstr("AT+CWMODE=3");
tx(0x0d);
tx(0x0a);
delay(2000);
lcdcmd(0x01);
lcdcmd(0x80);
lcddisplay("AT+CIPMUX=0");
txstr("AT+CIPMUX=0");
tx(0x0d);
tx(0x0a);
delay(2000);
lcdcmd(0x01);
while(1)
{
	
			if(s1==1)
			{
				send(id1,1);
				 delay(2000);
			   lcdcmd(0x01);
			}
			else 
			{
				send(id1,2);
				 delay(2000);
			   lcdcmd(0x01);
			}
					if(s2==1)
			{
				send(id2,1);
				 delay(2000);
			   lcdcmd(0x01);
		}
			else 
			{
				send(id2,2);
				 delay(2000);
			   lcdcmd(0x01);
		}
				if(s3==1)
			{
				send(id3,1);
				 delay(2000);
			   lcdcmd(0x01);
		}
			else 
			{
				send(id3,2);
				 delay(2000);
			   lcdcmd(0x01);
		}
				if(s4==1)
			{
				send(id4,1);
				 delay(2000);
			   lcdcmd(0x01);
		}
			else 
			{
				send(id4,2);
				 delay(2000);
			   lcdcmd(0x01);
		}


		}
}













