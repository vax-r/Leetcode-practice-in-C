bool checkVowel(char c) {
    switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
        default:
            return false;
    }
    return false;
}

bool halvesAreAlike(char* s) {
    int vowel1 = 0, vowel2 = 0;
    for (int i=0; i<strlen(s)/2; i++) {
        if (checkVowel(s[i]))
            vowel1++;
    }
    for (int i=strlen(s)/2; i<strlen(s); i++) {
        if (checkVowel(s[i]))
            vowel2++;
    }
    if (vowel1 == vowel2)
        return true;
    return false;
}