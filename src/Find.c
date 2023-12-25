#include "Find.h"
int Find(LinkList l,ElemType x){
    int len = Length(l);
    int *RL,RLlen = 0,times = 0;
    RL = (int *)malloc(sizeof(int)*len);
    LinkList p = l;
    for(int j = 0;j<len;j++){
        if(p->data == x){
            times++;
            RL[j] = 1;
        }
        else{
            RL[j] = 0;
        }
        p = p->next;
    }
    if(times == 0)return 0;
    else return 1;
}//If we want the other parameter of Find then we change in it.