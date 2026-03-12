#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - 1 - i];
        str[n - 1 - i] = temp;
    }
}

void toBase(long long num, int base, char* res) {
    if (num == 0) {
        strcpy(res, "0");
        return;
    }
    char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i = 0;
    while (num > 0) {
        res[i++] = digits[num % base];
        num /= base;
    }
    res[i] = '\0';
    reverse(res);
}

char* concatHex36(int n) {
    char h16[64];
    char h36[64];
    
    toBase((long long)n * n, 16, h16);
    toBase((long long)n * n * n, 36, h36);
    
    char* result = (char*)malloc(128 * sizeof(char));
    strcpy(result, h16);
    strcat(result, h36);
    
    return result;
}
