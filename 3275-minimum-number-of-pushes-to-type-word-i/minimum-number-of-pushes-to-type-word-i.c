#include <string.h>

int minimumPushes(char* word) {
    int n = strlen(word);
    int ans = 0;
    
    if (n <= 8) {
        ans = n;
    } else if (n <= 16) {
        ans = 8 + (n - 8) * 2;
    } else if (n <= 24) {
        ans = 24 + (n - 16) * 3;
    } else {
        ans = 48 + (n - 24) * 4;
    }
    
    return ans;
}
