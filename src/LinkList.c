//init a LinkList
#include "LinkList.h"
// we use double pointer to get the address of linklist
void InitLinkList(LinkList* l){
    *l = (LinkList)malloc(sizeof(Node));
    (*l)->data = 0;
    (*l)->next =( (void*)0);
}