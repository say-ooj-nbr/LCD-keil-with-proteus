#define RS 0 //rs=>p0.0
#define RW 1//rw=>p0.1
#define EN 2//en=>p0.2
//function declarations
void LCDcommand(unsigned char mycmd);
void LCDdata(unsigned char mydata);
void initLCD(void);
//Defining the function
void LCDcommand(unsigned char mycmd)
{
pinWrite(RS,0);// RS will be selected for command mode
pinWrite(RW,0);//will be selected for write
portWrite(1,mycmd);
pinWrite(EN,1);
delay();
pinWrite(EN,0);
}
void LCDdata(unsigned char mydata)
{
pinWrite(RS,1);
pinWrite(RW,0);
portWrite(1,mydata);
pinWrite(EN,1);
delay();
pinWrite(EN,0);
}
void initLCD(void)
{
LCDcommand(0x38);//16*2 lcd
LCDcommand(0x0C);//cursor off display on
LCDcommand(0x06);//entry mode
LCDcommand(0x01);//clear display
LCDcommand(0x80);//to start from 1st row
}