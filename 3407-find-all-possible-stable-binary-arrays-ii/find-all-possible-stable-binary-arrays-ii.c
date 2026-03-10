#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int numberOfStableArrays(int n, int m, int limit) {
    
    long long ***dp = (long long ***)malloc((n + 1) * sizeof(long long **));
    for (int i = 0; i <= n; i++) {
        dp[i] = (long long **)malloc((m + 1) * sizeof(long long *));
        for (int j = 0; j <= m; j++) {
            dp[i][j] = (long long *)calloc(2, sizeof(long long));
        }
    }

    
    for (int i = 0; i <= n && i <= limit; i++) {
        dp[i][0][0] = 1;
    }
   
    for (int j = 0; j <= m && j <= limit; j++) {
        dp[0][j][1] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
           
            long long val0 = (dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
            if (i > limit) {
                
                val0 = (val0 - dp[i - limit - 1][j][1] + MOD) % MOD;
            }
            dp[i][j][0] = val0;

            
            long long val1 = (dp[i][j - 1][0] + dp[i][j - 1][1]) % MOD;
            if (j > limit) {
                
                val1 = (val1 - dp[i][j - limit - 1][0] + MOD) % MOD;
            }
            dp[i][j][1] = val1;
        }
    }

    long long result = (dp[n][m][0] + dp[n][m][1]) % MOD;

    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            free(dp[i][j]);
        }
        free(dp[i]);
    }
    free(dp);

    return (int)result;
}