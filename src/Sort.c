#include "LinkListLib.h"
void Sort(LinkList *l,int o){
    int len = Length(*l);
    LinkList p = (*l)->next; // the first node have no data 
    for(int i = 1;i<len;i++){
        LinkList q = p->next;
        for(int j = i+1;j<len;j++){
            if((q->data < p->data)&&o){ //if we find a unorder member we just change thier data space
                ElemType m = q->data;
                q->data = p->data;
                p->data = m;
            }
            else if((q->data > p->data)&&!o){
                ElemType m = q->data;
                q->data = p->data;
                p->data = m;
            }
            q = q->next;
        }
        p = p->next;
    }        
}
