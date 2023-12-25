#include "Length.h"
int Length(LinkList l){
    LinkList  p = l;
    int len = 0;
    while(p){
        len++;
        p = p->next;
    }
    return len;
}