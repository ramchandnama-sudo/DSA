#include <stdio.h>
#include <stdlib.h>

long long minTime(int* skill, int skillSize, int* mana, int manaSize) {
    int n = skillSize;
    int m = manaSize;

    long long* prev = (long long*)malloc(n * sizeof(long long));
    long long time = 0;

    for (int i = 0; i < n; i++) {
        time += (long long)skill[i] * mana[0];
        prev[i] = time;
    }

    for (int j = 1; j < m; j++) {
        long long* pro = (long long*)malloc(n * sizeof(long long));
        for (int i = 0; i < n; i++) {
            pro[i] = (long long)skill[i] * mana[j];
        }

        long long* total = (long long*)malloc(n * sizeof(long long));
        total[0] = pro[0];
        for (int i = 1; i < n; i++) {
            total[i] = total[i - 1] + pro[i];
        }

        long long* starts = (long long*)malloc(n * sizeof(long long));
        starts[0] = prev[0];
        for (int i = 1; i < n; i++) {
            starts[i] = prev[i] - total[i - 1];
        }

        long long s = starts[0];
        for (int i = 1; i < n; i++) {
            if (starts[i] > s) s = starts[i];
        }

        long long* update = (long long*)malloc(n * sizeof(long long));
        update[0] = s + pro[0];
        for (int i = 1; i < n; i++) {
            update[i] = update[i - 1] + pro[i];
        }

        for (int i = 0; i < n; i++) {
            prev[i] = update[i];
        }

        free(pro);
        free(total);
        free(starts);
        free(update);
    }

    long long result = prev[n - 1];
    free(prev);
    return result;
}