#ifndef __MENU_H
#define __MENU_H


typedef struct MenuNode
{
	uint8_t wId;
	struct MenuNode* parentPtr;
	struct MenuNode* *childPtr;
	uint8_t MaxCap;
	uint8_t MLength;
}MenuNode;//�˵���һ���ڵ�

typedef struct Menu
{
	MenuNode* Mroot;
	MenuNode* nowNode;
}Menu;//�����˵�Ŀ¼

void Menu_Init(Menu* m,uint8_t MaxCap);//��ʼ��
void Menu_InsertNode(MenuNode* pos,uint8_t wId,uint8_t MaxCap);//����˵��ڵ�
void Menu_DeleteNode(Menu* m,MenuNode* pos);//ɾ���ڵ�

#endif
