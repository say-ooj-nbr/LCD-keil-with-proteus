//lcd.h
#define RS 0
#define RW 1
#define EN 2
#define LCDdataPort 1 // Group 1 of P0.8 to P0.15
void initLCD(void);
void LCDcommand(unsigned char mycmd);
void LCDdata(unsigned char mydata);
void LCDprint(unsigned char mydata[]);
void LCDsetcursor(int col, int row);
void LCDclear(void);
void LCDcommand(unsigned char mycmd)
{
pinWrite(RS,0);
pinWrite(RW,0);
portWrite(LCDdataPort,mycmd);
pinWrite(EN,1);
delay();
pinWrite(EN,0);
}
void LCDdata(unsigned char mydata)
{
pinWrite(RS,1);
pinWrite(RW,0);
portWrite(LCDdataPort,mydata);
pinWrite(EN,1);
delay();
pinWrite(EN,0);
}
void initLCD(void)
{
LCDcommand(0x38);
LCDcommand(0x0C);
LCDcommand(0x06);
LCDcommand(0x01);
LCDcommand(0x80);
}
void LCDprint(unsigned char mydata[])
{
int i=0;
// LCDprint("Hello EIE");
while(mydata[i]!='\0')
{
LCDdata(mydata[i]);
delay();
i++;
}
}
void LCDsetcursor(int col, int row)
{
if (row==0) // 0 -> first row
LCDcommand(0x80+col);
if (row==1) // 1 -> Second Row
LCDcommand(0xC0+col);
}
void LCDclear(void)
{
LCDcommand(0x01); // LCR cleared
}