#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* generateString(char* str1, char* str2) {
    int n = strlen(str1);
    int m = strlen(str2);
    int len = n + m - 1;
    char* word = (char*)malloc((len + 1) * sizeof(char));
    int* fixed = (int*)calloc(len, sizeof(int));

    for (int i = 0; i < len; i++) word[i] = '\0';

    for (int i = 0; i < n; i++) {
        if (str1[i] == 'T') {
            for (int j = 0; j < m; j++) {
                if (word[i + j] != '\0' && word[i + j] != str2[j]) {
                    free(word);
                    free(fixed);
                    return "";
                }
                word[i + j] = str2[j];
                fixed[i + j] = 1;
            }
        }
    }

    for (int i = 0; i < len; i++) {
        if (word[i] == '\0') word[i] = 'a';
    }

    for (int i = 0; i < n; i++) {
        if (str1[i] == 'F') {
            int match = 1;
            for (int j = 0; j < m; j++) {
                if (word[i + j] != str2[j]) {
                    match = 0;
                    break;
                }
            }

            if (match) {
                int changed = 0;
                for (int j = m - 1; j >= 0; j--) {
                    if (!fixed[i + j]) {
                        if (word[i + j] < 'z') {
                            for (char c = 'a'; c <= 'z'; c++) {
                                if (c != str2[j]) {
                                    word[i + j] = c;
                                    changed = 1;
                                    break;
                                }
                            }
                        }
                        if (changed) break;
                    }
                }
                if (!changed) {
                    free(word);
                    free(fixed);
                    return "";
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int match = 1;
        for (int j = 0; j < m; j++) {
            if (word[i + j] != str2[j]) {
                match = 0;
                break;
            }
        }
        if ((str1[i] == 'T' && !match) || (str1[i] == 'F' && match)) {
            free(word);
            free(fixed);
            return "";
        }
    }

    word[len] = '\0';
    free(fixed);
    return word;
}
