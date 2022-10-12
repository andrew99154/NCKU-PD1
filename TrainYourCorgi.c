typedef int Strength;
typedef int Obedience;

#define INIT_STRENGTH 50
#define INIT_OBEDIENCE 20

#define STRENGTH_EAT 5
#define OBEDIENCE_EAT 2

#define STRENGTH_TRAIN 4
#define OBEDIENCE_TRAIN 5

#define LEARN_STRENGTH 55
#define LEARN_OBEDIENCE 28

#include<stdio.h>
int main(){
    int counts = 0;
    char c;
    Strength theStg = INIT_STRENGTH;
    Obedience theOb = INIT_OBEDIENCE;
    while(c=getchar()){
        if(c=='\n')
            break;
        if(c=='e'){
            theStg += STRENGTH_EAT;
            theOb -= OBEDIENCE_EAT;
        }else if (c == 't'){
            theOb += OBEDIENCE_TRAIN;
            theStg -= STRENGTH_TRAIN;
        }
        if(theOb>=LEARN_OBEDIENCE && theStg<=LEARN_STRENGTH){
            counts++;
            theOb = INIT_OBEDIENCE;
        }
    }
    if(counts>=5)printf("Yes");
    else printf("No");
}