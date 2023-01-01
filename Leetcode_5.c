#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

char * longestPalindrome(char * s){
    if(strlen(s)==1)
        return s;

    int L[1000][1000]={0};
    int i=0,j,k,len,s_len=strlen(s);
    for(i=0;i<strlen(s)-1;i++){
        L[i][i]=1;
        if((int)s[i] == (int)s[i+1]){
            L[i][i+1]=2;
        }
    }
    L[strlen(s)-1][strlen(s)-1]=1;
    for(len=3;len<=strlen(s);len++){
        for(i=0;i<strlen(s)-len+1;i++){
            j = i+len-1;
            if((int)s[i] == (int)s[j] && L[i+1][j-1]>0){
                L[i][j] = L[i+1][j-1]+2;
            }
            else{
                L[i][j]=0;
            }
        }
    }

    int max_i,max_j,max_len=0;
    for(i=0;i<s_len;i++){
        for(j=0;j<s_len;j++){
            if(L[i][j]>max_len){
                max_i = i;
                max_j = j;
                max_len = L[i][j];
            }
        }
    }
    // char* LPS="a";
    char *LPS = malloc(sizeof(char)*(max_len+1));
    LPS[max_len]='\0';
    for(i=0;i<max_len;i++){
        LPS[i] = s[max_i+i];
    }
    return LPS;
}

int main(){
    char* s = "aacabdkacaa";
    char* ans = longestPalindrome(s);
    printf("%s\n",ans);
    return 0;
}