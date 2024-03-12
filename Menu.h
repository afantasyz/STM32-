#ifndef __MENU_H
#define __MENU_H

#include "widegt.h"

typedef struct MenuNode
{
	uint8_t wId;
	Widegt* w;
	struct MenuNode* parentPtr;
	struct MenuNode* *childPtr;
	uint8_t isLeaf;
	uint8_t MLength;
	uint8_t MaxCap;
}MenuNode;//�˵���һ���ڵ�

typedef struct Menu
{
	MenuNode* Mroot;
	MenuNode* nowNode;
}Menu;//�����˵�Ŀ¼

void Menu_Init(Menu* m,uint8_t cap);//��ʼ��
void Menu_InsertNode(MenuNode* pos,uint8_t wId,uint8_t cap);//����˵��ڵ�
void Menu_DeleteNode(Menu* m,MenuNode* pos);//ɾ����ǰ�ڵ����һ��Ŀ¼
void Menu_EnterWidegt(Menu* m,uint8_t Pnum);//����ѡ�в˵�
void Menu_ExitWidegt(Menu* m);//�˳��˵�

#endif
