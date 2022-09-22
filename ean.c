#include <stdio.h>

int toNum(char c){
    return c-48;
}
int main(void){
   	char tmp[12];
    int a,b,x,y,z;
    scanf("%s", tmp);
    a = toNum(tmp[1])+toNum(tmp[3])+toNum(tmp[5])+toNum(tmp[7])+toNum(tmp[9])+toNum(tmp[11]);
    b = toNum(tmp[0])+toNum(tmp[2])+toNum(tmp[4])+toNum(tmp[6])+toNum(tmp[8])+toNum(tmp[10]);
    x = a*3+b;
    y = x-1;
    z = 9-(y%10);
    printf("%d",z);
    return 0;
}