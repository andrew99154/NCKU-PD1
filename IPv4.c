#include<stdio.h>
#include<math.h>
#include<ctype.h>
int engToNum(char c){
    switch (c){
    case 'a': return 10;
    case 'b': return 11;
    case 'c': return 12;
    case 'd': return 13;
    case 'e': return 14;
    case 'f': return 15;
    }
}
int main(){
    char tmp[10];
    int sumTmp = 0;
    scanf("%s",&tmp);
    for(int i=0;i<8;i++){
        for(int j=1;j>=0;j--){
            if(isdigit(tmp[i]))sumTmp+=(tmp[i]-48)*pow(16,j);
            else sumTmp += engToNum(tmp[i])*pow(16,j);
            if(j)i++;
        }
        printf("%d",sumTmp);
        sumTmp = 0;
        if(i!=7)printf(".");
    }
}