#include<stdio.h>
int printBinary(unsigned int a){
    int tmp;
    for(int i=31;i>=0;i--){
        tmp = (a>>i) & 0x1;
        printf("%d",tmp);
        if(i%8==0)printf(" ");
    }
    printf("\n");
}
int main(){
    float a,b;
    scanf("%f%f",&a,&b);
    unsigned int aBinary=*(unsigned int*)&a, bBinary=*(unsigned int*)&b;
    printf("   ");
    printBinary(aBinary);
    printf("+) ");
    printBinary(bBinary);
    printf("---------------------------------------\n");
    printf("   ");
    printBinary(aBinary+bBinary);
    printf("%.f + %.f = %d",a,b,aBinary+bBinary);
}