#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 4096

void recovery(char *homework);

int main () {
    char homework[MAX_LEN + 1];
    
    // Get the homework content.
    fgets(homework, MAX_LEN , stdin);
    recovery(homework);

    // Print the recovered homework.
    fputs(homework, stdout);

    return 0;
}

void recovery(char *homework) {
    char ans[MAX_LEN+1] = {0};
    char partarr[MAX_LEN+1] = {0},tmp[MAX_LEN+1] = {0}, *part = partarr;
    int isword = 1;
    part = strtok(homework," \n");
    while(part!=NULL){
        isword = 1;
        strcpy(tmp,part);
        part = strtok(NULL," \n");
        int len = strlen(tmp);
        if(len>21)isword = 0;
        else if(len==1 && !isalpha(tmp[0]))isword = 0;
        else{
            for(int i=0;i<len;i++){
                if(!isalpha(tmp[i])){
                    if(i!=len-1 || (tmp[i] != '.'&&tmp[i] != ','&&tmp[i] != '!'&&tmp[i] != '?')){
                        isword = 0;
                        break;
                    }
                }
            }
        }

        if(isword){
            strcat(ans,tmp);
            if(part!=NULL)strcat(ans," ");
        }
    }
    strcpy(homework,ans);
}