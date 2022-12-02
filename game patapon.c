#include<stdio.h>
#include<string.h>

int checkReq(char req[]){
    if(strcmp(req,"PATA PATA PATA PON")==0)return 1;
    if(strcmp(req,"PON PON PATA PON")==0)return 2;
    if(strcmp(req,"CHAKA CHAKA PATA PON")==0)return 3;
    return 0;
}
int main () {
    int d,blood,reqTimes = 0,defense = 0,loss = 1,legal = 0;
    char nouse = '\0',sentence[750],*part;
    scanf("%d%d%c",&d,&blood,&nouse);
    gets(sentence);
    part = strtok(sentence,",.\n");
    while(part!=NULL){
        defense =0;
        int req = checkReq(part);
        reqTimes++;
        part = strtok(NULL,",.\n");
        if(req==0)continue;
        legal++;
        if(req==1){
            if(--d<=0)break;
        }
        else if(req==2){
            if(d<=3){
                if(--blood<=0){
                    loss=0;
                    break;
                }
            }
        }else if(req==3){
            d++;
            defense = 1;
        }
        if(reqTimes%10==0){
            if(!defense)break;
        }
    }
    if(loss)printf("NO %d",blood);
    else printf("YES %d",legal);
}
