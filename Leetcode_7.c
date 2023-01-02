#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define BOUND 2147483647

int reverse(int x){
    if(x<0 && x<=(-BOUND))
        return 0;
    if(x>=0 && x>=BOUND-1)
        return 0;

    int result = 0;
    int stack[11]={0},top=0,i;
    bool neg = false;
    
    if(x<0){
        x = -x;
        neg = true;
    }

    while(x>0){
        stack[top++] = (x % 10);
        x /= 10;
        if(top>10)//exceed limit
            return 0;
    }
    for(i=0;i<top;i++){
        if((!neg && result >= BOUND-1) || (neg && result >= BOUND) || (result >= 214748365)){
            return 0;
        }
        result *= 10;
        result += stack[i];

    }
    if(neg){
        if(result >= BOUND)
            return 0;
        result = -result;
    }
    return result;
}

int main(){
    int a = 123;
    int ans = reverse(a);
    printf("%d\n",ans);
    return 0;
}