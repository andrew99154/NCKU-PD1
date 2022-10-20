#include<stdio.h>

// 直接建立區間總和
int build(int l, int r,int *scorePeople, int *tree,int index){
    if(l == r){
        tree[index] = scorePeople[l];
        return tree[index];
    }
    int m = (l+r)/2;
    tree[index] = build(l,m,scorePeople,tree,2*index) + build(m+1,r,scorePeople,tree,2*index+1);
}

int query(int l, int r, int ql, int qr,int index,int *tree){
    if(l>=ql && r<=qr)return tree[index];
    if(l > qr) return 0;
    if(r < ql) return 0;
    if(l == r) return tree[index];
    int m = (l+r)/2;
    return query(l,m,ql,qr,index*2,tree) + query(m+1,r,ql,qr,index*2+1,tree);
}

int main(){
    int N, T, B, A, score, outLeft, outRight, inInterval;
    int scorePeople[110] = {0}, tree[410] = {0};
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&score);
        scorePeople[score]++;
    }
    build(0,100,scorePeople,tree,1);    
    scanf("%d",&T);
    while (T--){
        scanf("%d%d",&B,&A);
        outLeft = query(0,100,0,B-1,1,tree);
        inInterval = query(0,100,B,A-1,1,tree);
        outRight = query(0,100,A,100,1,tree);
        printf("%d %d %d\n",outLeft,inInterval,outRight);
    }
    
}