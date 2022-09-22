#include<stdio.h>
#include<math.h>
int main(){
    float a = 0,result = 0,threeSqrt = sqrt(3);
    scanf("%f",&a);
    result =threeSqrt/4*a*a;
    printf("%.3f",result);
}