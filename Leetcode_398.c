char findTheDifference(char* s, char* t) {
     int temp = 0;
     
     // sort the array s
     
     for(int i = 0 ; i < strlen(s) ; i++)
     {
         temp = temp ^ s[i] ^ t[i];
 
     }
     
    return temp ^ t[strlen(s)];
}
