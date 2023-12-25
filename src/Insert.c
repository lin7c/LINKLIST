#include "Insert.h"
void Insert(LinkList *l, ElemType x,int i){
    int len = Length(*l)-1;         
    if(i<0||i>len){
        printf("The Insert error");
        return;
    }
    LinkList p = *l;
    if(len == i){   //if length < 1 back insert
        for(int j = 0;j<i;j++){
            p = p->next;
        }
        p->next = (LinkList)malloc(sizeof(Node));
        p->next->data = x;
        p->next->next = (void*)0; //we define all end of linklist is nulptr  
    }
    else{
        for(int j = 0;j<i;j++){
            p = p->next;
        }
        LinkList N = (LinkList)malloc(sizeof(Node));
        N->next = p->next;
        p->next = N;
        N->data = x;
    }
}
