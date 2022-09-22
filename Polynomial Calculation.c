#include<stdio.h>
#include<math.h>
int main(){
    float a = 0,result = 0;
    scanf("%f",&a);
    result = 7*pow(a,4) - 8 * pow(a,3) - a*a + 6*a -22;
    printf("%.1f",result);
}