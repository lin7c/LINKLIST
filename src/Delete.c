#include "Delete.h"
int Delete(LinkList *l,ElemType x){
    int len = Length(*l);
    int *RL,RLlen = 0,times = 0;
    RL = (int*)malloc(sizeof(int)*len);
    LinkList p = *l;
    for(int j= 0 ;j<len;j++){
        if(p->data == x){
            times++;
            RL[j] = 1;
            RLlen++;
        }
        else{
            RL[j] = 0;
            RLlen++;
        }
        p = p->next;
    }
    if(times == 0){
        printf("no element to delete");
        return 0;
    }
    for(int k = 0;k<RLlen;k++){
        if(RL[k] == 1)
        Remove(l,k);
    }
    return 1;
}