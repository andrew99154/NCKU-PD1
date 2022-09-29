#include<stdio.h>
int main(){
    float x[10] = {0}, h[10] = {0};
    float w = 0.9,u = 0.1,b=-51,up=-0.98,bp=153;
    scanf("%f",&x[0]);
    for(int t=0;t<5;t++){
        h[t+1] = w*x[t]+u*h[t]+b;
        x[t+1] = up*h[t+1]+bp;
    }
    for(int i=1;i<=5;i++){
        printf("%.1f ",x[i]);
    }
}