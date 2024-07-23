void delay(void);
void pinWrite(int pinNr,int pinVal);
void portWrite(int portNr,int portVal);
int pinRead(int pinNr);
void delay(void)
{
int i;
for(i=0;i<20000;i++);
}
void pinWrite(int pinNr,int pinVal)
{
// pinWrite(19,1)
// if pinNr = 00 to 31 ==> Port 0
// if pinNr = 100 to 131 => Port 1
if (pinNr < 100)
{
IODIR0 = IODIR0 | (0x01 << pinNr);
if (pinVal == 1)
IOSET0 = IOSET0 | (0x01 << pinNr);
else if (pinVal==0)
IOCLR0 = IOCLR0 | (0x01 << pinNr);
else
pinVal=0; // Dummy
}
else
{ // Port-1
pinNr = pinNr-100;
IODIR1 = IODIR1 | (0x01 << pinNr);
if (pinVal == 1)
IOSET1 = IOSET1 | (0x01 << pinNr);
else if (pinVal==0)
IOCLR1 = IOCLR1 | (0x01 << pinNr);
else
pinVal=0; // Dummy
}
}
void portWrite(int portNr,int portVal)
{
if (portNr < 10)
{// Port-0
if (portNr == 0)
{
// Block-0 P0.0 to P0.7
// portWrite(0,0x32); 0011 0010
// 1100 1101
IODIR0 = IODIR0 | (0xFF);
IOSET0 = IOSET0 | (portVal);
IOCLR0 = IOCLR0 | ~(portVal);
}
else if (portNr==1)
{
// Blocl-1 P0.8 to P0.15
IODIR0 = IODIR0 | (0xFF00);
IOSET0 = IOSET0 | (portVal <<8);
IOCLR0 = IOCLR0 | (~(portVal) << 8);
}
else if (portNr==2)
{
// Block-2 P0.16 to P0.23
IODIR0 = IODIR0 | (0xFF0000);
IOSET0 = IOSET0 | (portVal << 16);
IOCLR0 = IOCLR0 | (~(portVal) << 16);
}
else if (portNr==3)
{
// Block-3 P0.24 to P0.31
IODIR0 = IODIR0 | (0xFF000000);
IOSET0 = IOSET0 | (portVal)<<24;
IOCLR0 = IOCLR0 | (~(portVal)<<24);
}
else if (portNr==4)
{
// All four blocks P0.0 to P0.31
IODIR0 = IODIR0 | (0xFFFFFFFF);
IOSET0 = IOSET0 | (portVal);
IOCLR0 = IOCLR0 | ~(portVal);
}
else
portVal = 0;// Dummy
}
else
{
// Port-1
if (portNr == 12)
{
// Block-2 P1.16 to P1.23
IODIR1 = IODIR1 | (0xFF0000);
IOSET1 = IOSET1 | (portVal << 16);
IOCLR1 = IOCLR1 | (~(portVal) << 16);
}
else if (portNr == 13)
{
// Block-3 P1.24 to P1.31
IODIR1 = IODIR1 | (0xFF000000);
IOSET1 = IOSET1 | (portVal << 24);
IOCLR1 = IOCLR1 | (~(portVal) << 24);
}
else if (portNr == 14)
{
// Full Port-1 P1.0 to P1.31
IODIR1 = IODIR1 | (0xFFFFFFFF);
IOSET1 = IOSET1 | (portVal);
IOCLR1 = IOCLR1 | ~(portVal);
}
else
portVal = 0 ; // Dummy
}
}
int pinRead(int pinNr)
{
int mydata;
if (pinNr < 100)
{
// if pinNr = 0 to 31=> Port0 pin
IODIR0 = IODIR0 & (~(0x01 << pinNr));
mydata = IOPIN0;
if ((mydata & (0x01 << pinNr)) == 0)
return 0;
else
return 1;
}
else
{
// if pinNr = 100 to 131 ==> Port1 pin
pinNr = pinNr-100;
IODIR1 = IODIR1 & (~(0x01 << pinNr));
mydata = IOPIN1;
if ((mydata & (0x01 << pinNr)) == 0)
return 0;
else
return 1;
}
}