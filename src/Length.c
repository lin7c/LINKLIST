#include "Length.h"
int Length(LinkList l){
    LinkList  p = l;
    int len = 0;
    while(p!=(void*)0){
        len++;
        p = p->next;
    }
    return len;
}