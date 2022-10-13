#define mask1 0xff000000
#define mask2 0x00ff0000
#define mask3 0x0000ff00
#define mask4 0x000000ff
#define lowerMask 0x0000ffff
#include<stdio.h>

unsigned int masked(unsigned int n, int th){
    if(th==1)return (n & mask1)>>24;
    if(th==2)return (n & mask2)>>16;
    if(th==3)return (n & mask3)>>8;
    if(th==4)return n & mask4;
}
int main(){
    unsigned int N,temp = 0x0000,tmp2 = 0x0000,result,test;
    int d1,d2,d3,d4;
    scanf("%u%d%d%d%d",&N,&d1,&d2,&d3,&d4);
    // test = N&mask3;
    tmp2 = masked(N,d1) ^ masked(N,d2);
    temp |= (tmp2 << 24);
    tmp2 = masked(N,d2) & masked(N,d3);
    temp |= (tmp2 << 16);
    tmp2 = masked(N,d3) | masked(N,d1);
    temp |= (tmp2 << 8);
    tmp2 = (~masked(N,d4))&mask4;
    temp |= tmp2;
    temp = temp >> (d1+d2+d3+d4) | temp << (32-d1-d2-d3-d4);
    result = (temp >>16) ^ (temp & lowerMask);
    printf("%u",result);
}