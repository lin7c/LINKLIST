#include "Remove.h"
int Remove(LinkList *l,int i){
    int len = Length(*l)-1;
    LinkList p = *l;
    if(len == 0){
        printf("the linklist have no member to delete");
        return 0;
    }
    if(len == i){   //delete the end of linklist
        for(int j = 0;j<i-1;j++){  //locate to the prevoius one in the end
            p = p->next;
        }
        LinkList D = p->next;
        p->next = (void*)0;
        free(D);
    }
    else{
        for(int j = 0;j<i-1;j++){
            p = p->next;
        }
        LinkList D = p->next;
        p->next= p->next->next;
        free(D);
    }
    return 1;
}