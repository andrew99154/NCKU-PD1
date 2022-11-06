#include<stdio.h>
#include<ctype.h>
int table[110][110],done[110],theSize[110] = {0},N;
void foo(int paper,int ref){
    table[paper][ref] = 1;
    if(theSize[ref]==0)
        return;
    for(int i=1;i<=N;i++){
        if(i!=ref && table[ref][i]==1)
            foo(paper,i);
    }
}
int main(){
    int paper,tmp = 0;
    char ref;
    scanf("%d",&N);
    while(1){
        scanf("%d",&paper);
        if(paper==0)break;
        scanf("%c",&ref);
        while(1){
            scanf("%c",&ref);
            if(!isdigit(ref)){
                table[paper][tmp] = 1;
                theSize[paper]++;
                tmp = 0;
                if(ref == '\n')break;
            }else tmp = tmp*10+(ref-48);
        }
    }
    for(int i=1;i<=N;i++){
        printf("%d -> ",i);
        foo(i,i);
        for(int j=1;j<=N;j++)
            if(table[i][j])printf("%d ",j);
        printf("\n");
    }
    return 0;
}