blog: https://blog.csdn.net/wxh0000mm/article/details/77863217

https://blog.csdn.net/asialee_bird/article/details/81412903

#define COM_TX_PORT GPIOA

#define COM_TX_PIN GPIO_Pin_4

#define COM_DATA_HIGH() GPIO_SetBits(COM_TX_PORT, COM_TX_PIN) //高电平
#define COM_DATA_LOW() GPIO_ResetBits(COM_TX_PORT, COM_TX_PIN) //低电平

u32 delayTime;



void VirtualCOM_ByteSend(u8 val)
{
u8 i = 0;
COM_DATA_LOW(); //起始位
Delay_us(delayTime);
for(i = 0; i < 8; i++) //8位数据位
{
if(val & 0x01)
COM_DATA_HIGH();
else
COM_DATA_LOW();
Delay_us(delayTime);
val >>= 1;
}
COM_DATA_HIGH(); //停止位
Delay_us(delayTime);
}


void VirtualCOM_ByteSend(u8 val)
{
u8 i;
IO_LOW(); //起始位，拉低电平
Delay(sometime);
for(i = 0; i < 8; i++) //8位数据位
{
if(val & 0x01)
IO_HIGH();
else
IO_LOW();
Dealy(sometime);
val >>= 1;
}
IO_HIGH(); //停止位，拉高电平
Delay(sometime);
}

void VirtualCOM_StringSend(u8 *str)
{
while(*str != 0)
{
VirtualCOM_ByteSend(*str);
str++;
}
}

void VirtualCOM_TX_GPIOConfig(void)

{

GPIO_InitTypeDef GPIO_InitStructure;

/* PA4最为数据输出口，模拟TX */

GPIO_InitStructure.GPIO_Pin = COM_TX_PIN;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_Init(COM_TX_PORT, &GPIO_InitStructure);
GPIO_SetBits(COM_TX_PORT, COM_TX_PIN);
}

