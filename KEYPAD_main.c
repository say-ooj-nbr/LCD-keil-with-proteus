//KEYPAD main.c

#include<LPC214x.h>
#include"keypad_GPIO.h"
#include"LCD.h"
#include"keypad2.h"
int main()
{
unsigned char mykey;
initLCD();
while(1)
{
mykey=getKeypad();
if(mykey!='x')
{
LCDdata(mykey);
delay();
}
}
}