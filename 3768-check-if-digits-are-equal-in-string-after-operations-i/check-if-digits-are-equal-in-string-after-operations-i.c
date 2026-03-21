#include <stdbool.h>
#include <string.h>

bool hasSameDigits(char* s) {
    int n = strlen(s);
    
    // Repeatedly perform the operation until length is 2
    while (n > 2) {
        for (int i = 0; i < n - 1; i++) {
            // Calculate sum modulo 10 and store back in the same array
            int d1 = s[i] - '0';
            int d2 = s[i + 1] - '0';
            s[i] = ((d1 + d2) % 10) + '0';
        }
        // String size reduces by 1 in each step
        n--;
    }
    
    // Check if the final two digits are equal
    return s[0] == s[1];
}