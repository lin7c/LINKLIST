#include <stdio.h>
#include "LinkListLib.h"
int main(){
    LinkList l1;
    InitLinkList(&l1);
    ElemType e = 0, i = 0;
    printf("Insert e in the back of i and input '# ' to stop\n");

    while (1) {
        if (e == -1 || i == -1) {
            break;
        }
        scanf("%d %d", &e, &i);
        printf("Insert %d in the back of %d\n", e, i);
        Insert(&l1, e, i);
    }

    printf("sort:\n");
    Sort(&l1, 0);
    printf("travel:");
    Travel(l1);
    
//pouse
    int x;
    printf("\nPouse");
    scanf("%d",&x);
}