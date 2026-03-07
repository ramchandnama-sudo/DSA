#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef MIN
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif

// Renamed from minOperations to minFlips to fix the declaration error
int minFlips(char* s) {
    int n = strlen(s);
    if (n == 0) return 0;

    // Allocation for DP arrays
    int (*pre)[2] = malloc(n * sizeof(int[2]));
    
    // Prefix DP: pre[i][0] ends with '0', pre[i][1] ends with '1'
    pre[0][0] = (s[0] == '1' ? 1 : 0);
    pre[0][1] = (s[0] == '0' ? 1 : 0);

    for (int i = 1; i < n; i++) {
        pre[i][0] = pre[i - 1][1] + (s[i] == '1' ? 1 : 0);
        pre[i][1] = pre[i - 1][0] + (s[i] == '0' ? 1 : 0);
    }

    int ans = MIN(pre[n - 1][0], pre[n - 1][1]);

    if (n % 2 != 0) {
        int (*suf)[2] = malloc(n * sizeof(int[2]));
        
        // Suffix DP: suf[i][0] starts with '0', suf[i][1] starts with '1'
        suf[n - 1][0] = (s[n - 1] == '1' ? 1 : 0);
        suf[n - 1][1] = (s[n - 1] == '0' ? 1 : 0);

        for (int i = n - 2; i >= 0; i--) {
            suf[i][0] = suf[i + 1][1] + (s[i] == '1' ? 1 : 0);
            suf[i][1] = suf[i + 1][0] + (s[i] == '0' ? 1 : 0);
        }

        for (int i = 0; i < n - 1; i++) {
            // Check rotation points (concatenating two alternating parts)
            ans = MIN(ans, pre[i][0] + suf[i + 1][0]);
            ans = MIN(ans, pre[i][1] + suf[i + 1][1]);
        }
        
        free(suf);
    }

    free(pre);
    return ans;
}
