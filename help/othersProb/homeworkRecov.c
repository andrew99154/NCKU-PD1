#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 4096

void recovery(char *homework){
    int lenH=strlen(homework),p=-1,q,idx=0;
    // homework[lenH-1]=' ';
    char newHw[MAX_LEN+1] = {0};
    int flag = 1;
    for(int i=0;i<lenH;i++){
        if (homework[i]==' '||homework[i]=='\n'){//check
            q=i;
            if ((q-p-1)>21||(q-p-1)<1)flag=0;
            if (flag){
                if(idx!=0)newHw[idx++] = ' ';
                for(int j=p+1;j<q;j++)newHw[idx++]=homework[j];
            }
            p=i;
            flag=1;
            if(homework[i]=='\n')break;
        }else if (!isalpha(homework[i])){
            if (homework[i]==','||homework[i]=='?'||homework[i]=='!'||homework[i]=='.'){
                if (!isalpha(homework[i-1]) || !isspace(homework[i+1]))flag=0;
            }else flag=0;
        }
    }
    strcpy(homework,newHw);
}

int main () {
    char homework[MAX_LEN + 1];
    
    // Get the homework content.
    fgets(homework, MAX_LEN , stdin);
    recovery(homework);

    // Print the recovered homework.
    fputs(homework, stdout);
    return 0;
}