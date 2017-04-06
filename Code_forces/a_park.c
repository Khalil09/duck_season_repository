#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int n, i;
    char output[100000];

    scanf("%d", &n);

    i = 0;
    while(n >=2){
        if((n >= 2)&&(n != 3)){
            output[i] = '1';
            n = n - 2;
            i++;
        } else if(n >= 3) {
            if(output[0] == '1'){
                output[0] = '7';
                output[i] = '1';
            }else {
                output[i] = '7';
            }
            n = n - 3;
            i++;
        }
    }

    printf("%s", output);

    return 0;
}
