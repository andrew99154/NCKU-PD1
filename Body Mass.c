#include<stdio.h>
#include<math.h>
int main () {
    float height=0,weight=0,bmi = 0;
    scanf("%f%f",&height,&weight);
    height /= 100;
    bmi = weight/pow(height,2);
    printf("%f",bmi);
    return 0;
}
