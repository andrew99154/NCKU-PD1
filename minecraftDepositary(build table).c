#include<stdio.h>

int calNeedBaseMaterial(int table[][25],int needAmount[],int material,int needBaseAmount[]){
    if(needBaseAmount[material] != 0)return needBaseAmount[material];
    for(int i=0;i<needAmount[material];i++){
        needBaseAmount[material] += calNeedBaseMaterial(table,needAmount,table[material][i],needBaseAmount);
    }
    return needBaseAmount[material];
}
int main(){
    int N, amount,table[25][25],needAmount[25] = {0},needBaseAmount[25] = {0},result = 0;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d",&amount);
        needAmount[i] = amount;
        if(amount == 0) needBaseAmount[i] = 1;
        for(int j=0;j<amount;j++)scanf("%d",&table[i][j]);
    }
    for(int i=1;i<=N;i++)result+=calNeedBaseMaterial(table,needAmount,i,needBaseAmount);
    printf("%d",result);
}