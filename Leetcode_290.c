#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

bool wordPattern(char * pattern, char * s){
    if(strcmp(s,pattern)==0 && strlen(pattern)>1)
        return false;

    char* dictionary[26];
    int k;
    for(k=0;k<26;k++)
        dictionary[k]=NULL;
    const char* d = " ";
    char* p = strtok(s,d);
    int i,j=0,size = strlen(pattern);
    while(p != NULL){
        if(j >= size)//s is too long
            return false;
        i = (int)pattern[j] % 26;
        if(dictionary[i] == NULL){
            for(k=0;k<26;k++){
                if(dictionary[k]!=NULL && strcmp(dictionary[k], p) == 0){
                    return false;
                }
            }
            dictionary[i] = p;
        }
        else if(strcmp(dictionary[i], p) != 0){
            // printf("F2\n");
            return false;
        }
        p = strtok(NULL, d);
        j++;
    }
    if(j<size)//s is too short
        return false;

    return true;
}

int main(){
    char pattern[] = "jquery";
    char s[] = "jquery";
    if(wordPattern(pattern,s)){
        printf("true\n");
    }
    else{
        printf("false\n");
    }

    return 0;
}