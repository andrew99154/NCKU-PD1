#include <stdio.h>
#include <string.h>
void readline(char s[]){
    char c;
    int i=0;
    while((c=getchar())!='\n')s[i++]=c;
    s[i]='.';
    s[++i]='\0';
}
int main(){
    char s[99999],walk[]="PATA PATA PATA PON",back[]="CHAKA CHAKA PATA PON",attack[]="PON PON PATA PON";
    int hp,dist,cmd=0,cmdall=0;
    _Bool flag=1,defense=0;
    scanf("%d %d",&dist,&hp);
    getchar();
    readline(s);
    int lenS=strlen(s),ind=-1;
    for(int i=0;i<lenS;i++){
        if (s[i]==','||s[i]=='.'){
            flag=1;
            cmd++;
            cmdall++;
            defense=0;
            switch (i-ind-1){
                case 18:
                    for(int j=ind+1;j<i;j++){
                        if (walk[j-ind-1]!=s[j]){
                            flag=0;
                            break;
                        }
                    }
                    if (flag)dist--;
                    break;
                case 20:
                    for(int j=ind+1;j<i;j++){
                        if (back[j-ind-1]!=s[j]){
                            flag=0;
                            break;
                        }
                    }
                    if (flag){
                        dist++;
                        defense=1;
                    }
                    break;
                case 16:
                    for(int j=ind+1;j<i;j++){
                        if (attack[j-ind-1]!=s[j]){
                            flag=0;
                            break;
                        }
                    }
                    if (flag&&dist<=3)hp--;
                    break;
                default:
                    cmd--;
                    break;
            }
            if (hp<=0){
                printf("YES %d",cmd);
                return 0;
            }
            else if (cmdall%10==0&&!defense){
                printf("NO %d",hp);
                return 0;
            }
            ind=i;
            if (dist<=0){
                printf("NO %d",hp);
                return 0;
            }
            
            
        }
    }
    printf("NO %d",hp);
    return 0;
}