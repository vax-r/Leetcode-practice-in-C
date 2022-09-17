#include <stdbool.h>

int Top(long long int* stack,int* top){
    if(*top==-1)
        return -201;//it's empty
    return stack[*top];
}

void Push(long long int* stack,int* top,int stackSize,long long int num){
    if(*top==stackSize)//stack is fulled
        return;
    *top+=1;
    stack[*top]=num;
}

void Pop(int* top){
    if(*top==-1)//it's empty
        return;
    *top-=1;
}

long long int evalRPN(char ** tokens, int tokensSize){
    long long int Ans;
    //init a stack
    long long int* stack=(long long int*)malloc(sizeof(long long int)*tokensSize);
    int* top=(int*)malloc(sizeof(int));
    *top=-1;
    
    long long int i,j,num,a,b;
    bool neg;
    
    for(i=0;i<tokensSize;i++){
        neg=false;
        switch(tokens[i][0]){
            case '+':
                a=Top(stack,top);
                Pop(top);
                b=Top(stack,top);
                Pop(top);
                Push(stack,top,tokensSize,a+b);
                break;
            case '-':
                num=0;
                for(j=0;tokens[i][j]!='\0';j++)
                    if(j>0){
                        //it's a negative number
                        neg=true;
                        num=num*10+(tokens[i][j]-'0');  
                    }
                num=-num;
                if(neg)
                    Push(stack,top,tokensSize,num);
                else{
                    a=Top(stack,top);
                    Pop(top);
                    b=Top(stack,top);
                    Pop(top);
                    Push(stack,top,tokensSize,b-a);
                }
                break;
            case '*':
                a=Top(stack,top);
                Pop(top);
                b=Top(stack,top);
                Pop(top);
                Push(stack,top,tokensSize,a*b);
                break;
            case '/':
                a=Top(stack,top);
                Pop(top);
                b=Top(stack,top);
                Pop(top);
                Push(stack,top,tokensSize,b/a);
                break;
            default: //it's a positive number
                num=0;
                for(j=0;tokens[i][j]!='\0';j++){
                    num=num*10+(tokens[i][j]-'0');
                }
                Push(stack,top,tokensSize,num);
        }    
    }

    Ans=Top(stack,top);
    free(stack);
    free(top);

    return Ans;
}