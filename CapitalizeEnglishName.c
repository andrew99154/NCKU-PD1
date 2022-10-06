#include<stdio.h>
#include<stdbool.h>
char turnCap(char c){
    if(c>=97) c -= 32;
    return c;
}
char turnSmall(char c){
    if(c>=65 && c<97)c+=32;
    return c;
}
int main(){
    int n,count=0;
    scanf("%d",&n);
    char tmp;
    bool isFirst = true;
    while(count<n){
        scanf("%c", &tmp);
        if(tmp == ' ' || tmp== ',' || tmp==';' || tmp =='\n' || tmp == '.'){
            isFirst = true;
            if(tmp == ' ')printf(" ");
            else if(tmp==','||tmp==';'||tmp == '.'){
                printf("\n");
                count++;
            }
            continue;
        }
        if(isFirst){
            printf("%c",turnCap(tmp));
            isFirst = false;
        }else{
            printf("%c",turnSmall(tmp));
        }

    }

}