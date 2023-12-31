#include <stdio.h>
#include "LinkListLib.h"
int main(){
    LinkList l1;
    InitLinkList(&l1);
    Insert(&l1,1,0);
    Insert(&l1,1,0);
    Insert(&l1,2,2);
    Insert(&l1,1,0);
    Insert(&l1,1,0);
    printf("%d",Length(l1));
    Delete(&l1,2);
    Travel(l1);
//pouse
    int x;
    printf("\nPouse");
    scanf("%d",&x);
}