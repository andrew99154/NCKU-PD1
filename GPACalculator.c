#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>

float turnPoint(char c){
    if (c == 'A') return 4.0;
    if (c == 'B') return 3.0;
    if (c == 'C') return 2.0;
    if (c == 'F') return 0;
}
int main(){
    char s;
    int creditSum = 0; 
    float result = 0,credit,grade;
    bool isFirst = true;
    while(s = getchar()){
        if(s == '\n'){
            result += credit*grade;
            break;
        }
        if(isdigit(s)){
            if(isFirst)isFirst = false;
            else result+= credit*grade;
            credit = s-48;
            creditSum += s-48;
        }
        else{
            if(s == 'A' || s == 'B' || s == 'C' || s =='F')grade = turnPoint(s);
            else{
                if(s=='+') grade+=0.3;
                else if(s=='-')grade -= 0.3;
            }
        }
    }
    printf("%.2f",result/(float)creditSum);
}