

bool isAnagram(char* s, char* t) {
    if (strlen(s) != strlen(t)) return false;
    int count[26] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) return false;
    }
    return true;
}


char** removeAnagrams(char** words, int wordsSize, int* returnSize) {
    char** result = (char**)malloc(wordsSize * sizeof(char*));
    int count = 0;
    
   
    result[count++] = words[0];
    
    for (int i = 1; i < wordsSize; i++) {
        
        if (!isAnagram(result[count - 1], words[i])) {
            result[count++] = words[i];
        }
    }
    
    *returnSize = count;
    return result;
}
