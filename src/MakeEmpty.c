// the all data-space of node are setted in 0 and pointer are not changed 
#include "MakeEmpty.h"
void MakeEmpty(LinkList *l){
    LinkList p = (*l)->next;           //define a travel pointer 
    while(p){                //travel linklist and set all node-data in 0
        p->data = 0;
        p = p->next;
    }
}