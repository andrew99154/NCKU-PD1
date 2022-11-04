#include<stdio.h>
#include<ctype.h>
int refBy[110][110] = {{0}},ref[110][110] ={{0}},inDegree[110] = {0},queue[110] = {0};
int main(){
    int queueIndex = 0,queueSize = 0,N,paper;
    char tmp;
    scanf("%d",&N);
    while (1){
        scanf("%d",&paper);
        if(paper == 0)break;
        while (1){
            scanf("%c",&tmp);
            if(tmp == '\n')break;
            if(!isdigit(tmp))continue;
            refBy[(int)tmp-48][paper] = 1;
            inDegree[paper]++;
        }    
    }
    for(int i=1;i<=N;i++){
        ref[i][i] = 1;
        if(inDegree[i]==0)queue[queueSize++] = i;
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
        if (queueSize == N)break;
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