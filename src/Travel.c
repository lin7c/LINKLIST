#include "Travel.h"

void Travel(LinkList l){
    int len = Length(l);
    LinkList p = l->next;
    for(int i = 1;i<len;i++){
        printf("%d->",p->data);
        p = p->next;
    }
}
