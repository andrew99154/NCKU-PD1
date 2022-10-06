#include<stdio.h>
int main(){
    int n;
    long tmp[100010],stmp[100010];
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%ld",&tmp[i]);
    stmp[0] = tmp[0];
    for(int i=1;i<n;i++)stmp[i] = stmp[i-1]+tmp[i];
    for(int i=0;i<n;i++){
        if(stmp[i]%tmp[i]==0)printf("%ld %ld\n",stmp[i],tmp[i]);
    }
}