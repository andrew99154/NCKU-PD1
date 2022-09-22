#include<stdio.h>

int main () {
    int all,group;
    scanf("%d%d",&all,&group);
    printf("%d %d",all/group,all%group);
    return 0;
}