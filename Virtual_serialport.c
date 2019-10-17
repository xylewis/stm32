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


# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
import matplotlib.pyplot as plt
import numpy as np
  
from sklearn.naive_bayes import GaussianNB

from sklearn.metrics import accuracy_score,classification_report  
from sklearn.datasets import load_digits #
from sklearn import svm
from PIL import Image

dig=load_digits(n_class=10) #读入数字图像库，10类数字

plt.imshow(dig.data[:1].reshape(8,8),cmap ='gray')

plt.show()



























#y_pres=svm_model.predict(xtest)
#fig,ax=plt.subplots(5,5,figsize=(10,10))
#plt.figure(1)
#for i,axi in enumerate(ax.flatten()):  #flatten把数组展平
#    axi.imshow(dig.images[1501+i],cmap='binary')
#    axi.set(xticks=[],yticks=[],title="{}::{}".format(ytest[i],y_pres[i]))

