#ifndef LINKLIST_H
#define LINKLIST_H
#include<stdlib.h>
// if you want to change types of the data space in Node 
#define ElemType int
typedef struct Node
{
    ElemType data;
    struct Node * next;
}Node,*LinkList;
void InitLinkList(LinkList l);
#endif 