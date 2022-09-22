#include <stdio.h>
#define AMERICANO  110
#define LATTE      150
#define CAPPUCCINO 135
#define MOCHA      145

int main() {
    int coffee, amount, price;
    scanf("%d%d",&coffee,&amount);
    if(coffee>4)printf("Wait, what?");
    else{
        if(coffee == 1) price = AMERICANO*amount;
        else if(coffee ==2) price = LATTE*amount;
        else if(coffee ==3) price = CAPPUCCINO*amount;
        else price = MOCHA*amount;
        printf("The total price is %d dollars!", price);
    }
    return 0;
}