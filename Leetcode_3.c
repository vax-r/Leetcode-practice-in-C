#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

int lengthOfLongestSubstring(char * s){
    if(strcmp(s,"")==0)
        return 0;
    int k,l,r,s_len,result=1,partial_len;
    bool take;
    s_len = strlen(s);
    for(l=0;l<s_len;l++){
        partial_len = 1;
        for(r=l+1;r<s_len;r++){
            take = true;
            for(k=l;k<r;k++)
                if((int)s[k]==(int)s[r]){
                    take = false;
                    break;
                }
            if(!take)//有重複
                break;
            partial_len++;
        }
        if(partial_len>result)
            result = partial_len;
    }

    return result;
}

int main(){
    char* s = "";
    int ans = lengthOfLongestSubstring(s);
    printf("%d\n",ans);

    return 0;
}