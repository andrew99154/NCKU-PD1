#include<stdio.h>

void topLeft(int l){
    for(int i=l;i>0;i--){
        for(int j =0;j<i;j++)printf("*");
        printf("\n");
    }
}

void bottomLeft(int l){
    for(int i=1;i<=l;i++){
        for(int j =1;j<=i;j++)printf("*");
        printf("\n");
    }
}

void topRight(int l){
    for(int i=0;i<l;i++){
        for(int k = 0;k<i;k++)printf(" ");
        for(int j =0;j<l-i;j++)printf("*");
        printf("\n");
    }
}

void bottomRight(int l){
    for(int i=l-1;i>=0;i--){
        for(int k = 1;k<=i;k++)printf(" ");
        for(int j =0;j<l-i;j++)printf("*");
        printf("\n");
    }
}


int main () {
    int layers = 0;
    int direction = 0;
    scanf("%d%d",&direction,&layers);
    if(direction == 1)topLeft(layers);
    else if(direction == 2)bottomLeft(layers);
    else if(direction == 3)topRight(layers);
    else bottomRight(layers);
    return 0;
}

