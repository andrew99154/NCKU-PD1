#include<stdio.h>
int main(){
    unsigned long long n1 = 0x38E38E38E38E3800LLU, n2 = 0x2AAAAAAAAAAAAAAALLU, n3 = 0x1C71C71C71C71C71LLU, toMod = 0x7CE66C50E2840000LLU;
    unsigned long long p1,p2,p3,result;
    scanf("%llu%llu%llu",&p1,&p2,&p3);
    result = (((p1*n1% toMod) + (p2*n2% toMod))%toMod + (p3*n3%toMod)) % toMod;
    printf("%llu",result);
}