#include <stdlib.h>
#include <string.h>

char* getHappyString(int n, int k) {
    int total = 3 * (1 << (n - 1));
    if (k > total) {
        char* empty = (char*)malloc(1);
        empty[0] = '\0';
        return empty;
    }

    char* res = (char*)malloc(n + 1);
    res[n] = '\0';
    k--;

    int group_size = 1 << (n - 1);
    res[0] = 'a' + (k / group_size);
    k %= group_size;

    for (int i = 1; i < n; i++) {
        group_size >>= 1;
        int next_idx = k / group_size;
        
        char current = 'a';
        int count = 0;
        while (1) {
            if (current != res[i - 1]) {
                if (count == next_idx) {
                    res[i] = current;
                    break;
                }
                count++;
            }
            current++;
        }
        k %= group_size;
    }

    return res;
}
