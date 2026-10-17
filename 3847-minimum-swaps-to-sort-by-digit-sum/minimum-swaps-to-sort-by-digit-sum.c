typedef struct {
    int digitSum;
    int value;
    int index;
} Item;

int compare(const void* a, const void* b) {
    const Item* x = (const Item*)a;
    const Item* y = (const Item*)b;

    if (x->digitSum != y->digitSum) {
        return (x->digitSum > y->digitSum) -
               (x->digitSum < y->digitSum);
    }

    if (x->value != y->value) {
        return (x->value > y->value) -
               (x->value < y->value);
    }

    return (x->index > y->index) -
           (x->index < y->index);
}

int minSwaps(int* nums, int numsSize) {
    int n = numsSize;

    Item* arr = malloc(n * sizeof(Item));

    for (int i = 0; i < n; i++) {
        int curr = nums[i];
        int digitSum = 0;

        while (curr > 0) {
            digitSum += curr % 10;
            curr /= 10;
        }

        arr[i].digitSum = digitSum;
        arr[i].value = nums[i];
        arr[i].index = i;
    }

    qsort(arr, n, sizeof(Item), compare);

    int* perm = malloc(n * sizeof(int));
    bool* visited = calloc(n, sizeof(bool));

    for (int i = 0; i < n; i++) {
        perm[i] = arr[i].index;
    }

    int cycles = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            continue;
        }

        cycles++;
        int j = i;

        while (!visited[j]) {
            visited[j] = true;
            j = perm[j];
        }
    }

    free(arr);
    free(perm);
    free(visited);

    return n - cycles;
}