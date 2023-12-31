#include "Delete.h"
#include <stdio.h>
int Delete(LinkList *l,ElemType x){
    int len = Length(*l)-1; //if 1->1->1 is 4
    int *RL,times = 0;
    RL = (ElemType*)malloc(sizeof(ElemType)*len); //is [0,0,0]
    LinkList p = (*l)->next;
    for(int j= 0 ;j<len;j++){ // 3 
        printf("x");
        if(p->data == x){
            times++;
            RL[j] = 1;
        }
        else{
            RL[j] = 0;
        }
        p = p->next;
    }
    if(times == 0){
        printf("no element to delete");
        return 0;
    }
    int deltimes = 0;
    for(int k = 0;k<len;k++){
        if(RL[k] == 1){
            Remove(l,k-deltimes+1);
            deltimes++;
        }
    }
    return 1;
}