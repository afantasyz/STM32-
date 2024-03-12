#ifndef __WIDEGT_H
#define __WIDEGT_H

typedef struct TextNode
{
	char text[16];
	struct TextNode* nextNode;
	struct TextNode* lastNode;
	uint8_t textId;
}TextNode;//ѡ���ı�������

typedef struct Widegt
{
	TextNode* TextList;
	uint8_t textLength;
	TextNode* nowText;
	char head[16];
}Widegt;//����������ı�����

void Widegt_Show(Widegt* w);//��ʾ�ı�
void Widegt_Refresh(Widegt* w,uint8_t dir);//���µ�ǰѡ��
void Widegt_InsertTextNode(Widegt* w,char* newNode);//�����µ�Ԫ��
void Widegt_Init(Widegt* w,char* headName);//��ʼ��
void Widegt_DeInit(Widegt* w);//�����ڴ�

#endif
