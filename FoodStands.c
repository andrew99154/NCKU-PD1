#include<stdio.h>
#include<math.h>

int main () {
    int distance = 0, maxs = -1, mins = __INT_MAX__;
    while(distance!=-1){
        scanf("%d",&distance);
        if (distance == -1) break;
        mins = (distance < mins ? distance:mins);
        maxs = (distance > maxs ? distance:maxs);
    }
    printf("%d",maxs-mins);
    return 0;
}