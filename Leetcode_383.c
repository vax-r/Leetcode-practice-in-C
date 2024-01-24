bool canConstruct(char* ransomNote, char* magazine) {
    int count1[26] = {0};
    int count2[26] = {0};
    for (int i = 0; i < strlen(ransomNote); i++)
        count1[ransomNote[i] % 26] += 1;
    for (int i = 0; i < strlen(magazine); i++)
        count2[magazine[i] % 26] += 1;
    
    for (int i = 0; i < 26; i++)
        if (count1[i] > count2[i])
            return false;
    return true;
}