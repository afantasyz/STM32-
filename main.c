#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "widegt.h"
#include "Menu.h"
#include "Key.h"
#include "stdlib.h"

static Menu m;
void Program_Init(void);
	
int main(void)
{
	OLED_Init();
	Key_Init('B',GPIO_Pin_15);
	Key_Init('B',GPIO_Pin_12);
	Key_Init('A',GPIO_Pin_9);
	Key_Init('A',GPIO_Pin_12);//�ĸ������ֱ����ȷ����ȡ�����ϣ���
	Program_Init();
	Widegt* w=(Widegt*)malloc(sizeof(Widegt));;
	w=Widegt_Load(w,0);
	
	while(1)
	{
		if(KeyValue('B',GPIO_Pin_15)==1)
		{
			Widegt_Refresh(w,1);
		}
		
		if(KeyValue('B',GPIO_Pin_12)==1)
		{
			if(m.nowNode->childPtr!=NULL&&w->nowText->textId<m.nowNode->MLength)
			{
				uint8_t i=w->nowText->textId;
				w=Widegt_Load(w,m.nowNode->childPtr[i]->wId);
				m.nowNode=m.nowNode->childPtr[i];
			}
		}
		
		if(KeyValue('A',GPIO_Pin_9)==1)
		{
			Widegt_Refresh(w,0);
		}
		
		if(KeyValue('A',GPIO_Pin_12)==1)
		{
			if(m.nowNode!=m.Mroot)
			{
				w=Widegt_Load(w,m.nowNode->parentPtr->wId);
				m.nowNode=m.nowNode->parentPtr;
			}
		}
		
	}
}

void Program_Init(void)
{
	Menu_Init(&m,6);
	
	Menu_InsertNode(m.nowNode,1,1);
	Menu_InsertNode(m.nowNode,2,0);
	
	Menu_InsertNode(m.nowNode->childPtr[0],7,0);
}

//���ַ�ʽ��˼·��ֻ��һ������widegt�����ݴ����wid��ͬչʾ��ͬ�����ݣ�����ʹ��if else����ʾwid֮��Ĺ�ϵ
//Ҳ����ʹ������Menu�����洢wid֮��Ĺ�ϵ��ǰ�߷����޸Ľ�ʡ�����ڴ棬���������ݽṹ���߼�������
