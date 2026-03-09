#define MOD 1000000007

long long dp[201][201][2][201]; 
int memo[201][201][2][201];      
long long countWays(int zero, int one, int last, int consecutive, int limit) {
    
    if (zero == 0 && one == 0) {
        return 1;
    }
    
   
    if (consecutive > limit) {
        return 0;
    }
    
    
    if (memo[zero][one][last][consecutive]) {
        return dp[zero][one][last][consecutive];
    }
    
    long long result = 0;
    
    
    if (zero > 0) {
        if (last == 0 && consecutive < limit) {
           
            result = (result + countWays(zero - 1, one, 0, consecutive + 1, limit)) % MOD;
        } else if (last == 1) {
           
            result = (result + countWays(zero - 1, one, 0, 1, limit)) % MOD;
        }
    }
    
    
    if (one > 0) {
        if (last == 1 && consecutive < limit) {
            
            result = (result + countWays(zero, one - 1, 1, consecutive + 1, limit)) % MOD;
        } else if (last == 0) {
            
            result = (result + countWays(zero, one - 1, 1, 1, limit)) % MOD;
        }
    }
    
    memo[zero][one][last][consecutive] = 1;
    dp[zero][one][last][consecutive] = result;
    return result;
}

int numberOfStableArrays(int zero, int one, int limit) {
    
    for (int i = 0; i <= zero; i++) {
        for (int j = 0; j <= one; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l <= limit; l++) {
                    memo[i][j][k][l] = 0;
                }
            }
        }
    }
    
    
    long long result = 0;
    
   
    if (zero > 0) {
        result = (result + countWays(zero - 1, one, 0, 1, limit)) % MOD;
    }
    
  
    if (one > 0) {
        result = (result + countWays(zero, one - 1, 1, 1, limit)) % MOD;
    }
    
    return (int)result;
}