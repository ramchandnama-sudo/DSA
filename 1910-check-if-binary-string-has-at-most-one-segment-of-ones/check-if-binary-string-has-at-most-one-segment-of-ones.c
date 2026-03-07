#include <string.h>
#include <stdbool.h>

bool checkOnesSegment(char* s) {
   
    for (int i = 0; s[i + 1] != '\0'; i++) {
        if (s[i] == '0' && s[i + 1] == '1') {
            return false;
        }
    }
    return true;
}