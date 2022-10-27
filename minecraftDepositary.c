#include<stdio.h>
int N;
int calMaterials(int material,int table[][25]){
    if(table[material][0]==0) return 1;
    int sum = 0;
    for(int i=1;i<=table[material][0];i++){
        sum += calMaterials(table[material][i],table);
    }
    return sum;
}

int main () {
    int M,sum = 0;
    int table[25][25] = {{0}};
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d",&M);
        table[i][0] = M;
        for(int j=1;j<=M;j++)scanf("%d",&table[i][j]);
    }
    int lln = 1;
    for(int i=1;i<=N;i++)sum += calMaterials(i,table);
    printf("%d",sum);
    return 0;
}
