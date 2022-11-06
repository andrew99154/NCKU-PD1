#include<stdio.h>
#include<ctype.h>
int main(){
    int refBy[110][110] = {{0}},ref[110][110] ={{0}},inDegree[110] = {0},queue[110] = {0};
    int queueIndex = 0,queueSize = 0,N,paper,tmpIndex = 0;
    char tmp;
    scanf("%d",&N);
    while (1){
        scanf("%d",&paper);
        if(paper == 0)break;
        scanf("%c",&tmp);
        while (1){
            scanf("%c",&tmp);
            if(!isdigit(tmp)){
                refBy[tmpIndex][paper] = 1;
                inDegree[paper]++;
                tmpIndex=0;
                if(tmp=='\n')break;
            }else{
                tmpIndex = tmpIndex*10 + (tmp-48);
            }
        }    
    }
    for(int i=1;i<=N;i++){
        if(inDegree[i]==0)queue[queueSize++] = i;
        ref[i][i]=1;
    }
    while (queueIndex<queueSize){
        for(int i=1;i<=N;i++){
            if(refBy[queue[queueIndex]][i] == 1){
                for(int j=1;j<=N;j++){
                    if(ref[queue[queueIndex]][j])ref[i][j] = 1;
                }
                inDegree[i]--;
                if(inDegree[i]==0)queue[queueSize++] = i;
            }
        }
        queueIndex++;
    }

    for(int i=1;i<=N;i++){
        printf("%d ->",i);
        for(int j=1;j<=N;j++){
            if(ref[i][j])printf(" %d",j);
        }
        printf("\n");
    }
}