#ifndef __WIDEGTCONFIG_H
#define __WIDEGTCONFIG_H

#include "widegt.h"
#include "Menu.h"

Widegt* Widegt_Load(uint8_t wId);
//��ǰΪ�˽�Լ�ѿռ���õĲ�����ÿ���л�ҳ���Ѳ�չʾ��widegt�ͷŵ������Ҫ��һ����Լ�ռ�
//����ÿ�μ�������ǰ�ڵ����һ�㣬�����Ǽ�������Ŀ¼��

void MenuNode_Load(Menu* m,uint8_t wId);

#endif
