#include<stdio.h>
int main(){
    double result=1,tmp;
    for(int i=0;i<5;i++){
        scanf("%lf",&tmp);
        result*=tmp;
    }
    printf("%.15lf",result);
    
}