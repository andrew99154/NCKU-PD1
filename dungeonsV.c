#include<stdio.h>
int main(){
    int password[7] = {0},count = 75, d1, d2;
    while(count--){
        scanf("%d%d",&d1,&d2);
        if(d2%2)password[d1] = (password[d1]+11)%10;
        else password[d1] = (password[d1]+9)%10;
    }
    for(int i=1;i<=6;i++)printf("%d ",password[i]);
}