#include <stdlib.h>

#define MOD 1000000007

typedef struct {
    long* nums;
    int size;
    long a;
    long b;
} Fancy;

long power(long base, long exp) {
    long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long modInverse(long n) {
    return power(n, MOD - 2);
}

Fancy* fancyCreate() {
    Fancy* obj = (Fancy*)malloc(sizeof(Fancy));
    obj->nums = (long*)malloc(100001 * sizeof(long));
    obj->size = 0;
    obj->a = 1;
    obj->b = 0;
    return obj;
}

void fancyAppend(Fancy* obj, int val) {
    long invA = modInverse(obj->a);
    long transformed = ((long)val - obj->b + MOD) % MOD;
    transformed = (transformed * invA) % MOD;
    obj->nums[obj->size++] = transformed;
}

void fancyAddAll(Fancy* obj, int inc) {
    obj->b = (obj->b + inc) % MOD;
}

void fancyMultAll(Fancy* obj, int m) {
    obj->a = (obj->a * m) % MOD;
    obj->b = (obj->b * m) % MOD;
}

int fancyGetIndex(Fancy* obj, int idx) {
    if (idx >= obj->size) return -1;
    return (int)((obj->nums[idx] * obj->a + obj->b) % MOD);
}

void fancyFree(Fancy* obj) {
    free(obj->nums);
    free(obj);
}
