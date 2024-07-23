//keypad.h
#define c1 116
#define c2 117
#define c3 118
#define KeyPort 12 // port 1 block2
unsigned char getKeypad(void);//returns which key user is pressed
unsigned char getKeypad(void)
{
unsigned char key = 'x';
int mydata;
while(key=='x')//while loop should terminate when the user presses the key
{//LSB MSB
/*C1 C2 C3 x R1 R2 R3 R4
1 1 1 1 0 1 1 1 = 0x EF
1 1 1 1 1 0 1 1 = 0x DF
1 1 1 1 1 1 0 1 = 0x BF
1 1 1 1 1 1 1 0 = 0x 7F */
portWrite(KeyPort,0xEF);
mydata = pinRead(c1);
if (mydata==0)
{
key = '1';
break;
}
mydata = pinRead(c2);
if (mydata==0)
{
key = '2';
break;
}
mydata = pinRead(c3);
if (mydata==0)
{
key = '3';
break;
}
portWrite(KeyPort,0xDF);
mydata = pinRead(c1);
if (mydata==0)
{
key = '4';
break;
}
mydata = pinRead(c2);
if (mydata==0)
{
key = '5';
break;
}
mydata = pinRead(c3);
if (mydata==0)
{
key = '6';
break;
}
portWrite(KeyPort,0xBF);
mydata = pinRead(c1);
if (mydata==0)
{
key = '7';
break;
}
mydata = pinRead(c2);
if (mydata==0)
{
key = '8';
break;
}
mydata = pinRead(c3);
if (mydata==0)
{
key = '9';
break;
}
portWrite(KeyPort,0x7F);
mydata = pinRead(c1);
if (mydata==0)
{
key = '*';
break;
}
mydata = pinRead(c2);
if (mydata==0)
{
key = '0';
break;
}
mydata = pinRead(c3);
if (mydata==0)
{
key = '#';
break;
}
}
return key;//if condition fails it will return some key value
}