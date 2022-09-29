#include<stdio.h>
#include<math.h>
int main(){
    int d1,d2,d3,d4,d5,d6,attacker,player = 100,dragon = 100;
    while(dragon>0 && player>0){
        scanf("%d%d%d%d%d%d",&d1,&d2,&d3,&d4,&d5,&d6);
        attacker = d1+d2+d3;
        if(attacker%2){
            if(d6>d5&&d5>d4)dragon-=25;
            else if( d4%2 == d5%2 || d5%2 == d6%2)dragon-=5;
            if(dragon<=0){
                printf("Player wins");
                break;
            }
        }else{
            if(abs(d5-d4)>d6)player-=15;
            else if(d4+d5!=d6)player-=5;
            if(player<=0){
                printf("Dragon wins");
                break;
            }
        }
    }
}