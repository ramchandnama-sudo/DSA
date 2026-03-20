#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
    int val;
    int type; 
} Event;

int compareEvents(const void* a, const void* b) {
    Event* e1 = (Event*)a;
    Event* e2 = (Event*)b;
    if (e1->val != e2->val) return e1->val - e2->val;
    return e1->type - e2->type;
}

int compareInts(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int maxFrequency(int* nums, int numsSize, int k, int numOperations) {
    qsort(nums, numsSize, sizeof(int), compareInts);

    Event* events = (Event*)malloc(3 * numsSize * sizeof(Event));
    int eventCount = 0;

    for (int i = 0; i < numsSize; i++) {
        events[eventCount++] = (Event){nums[i] - k, 0};
        events[eventCount++] = (Event){nums[i], 1};
        events[eventCount++] = (Event){nums[i] + k + 1, -1};
    }

    qsort(events, eventCount, sizeof(Event), compareEvents);

    int max_freq = 0;
    int active_ranges = 0;
    int i = 0;

    while (i < eventCount) {
        int current_pos = events[i].val;
        int current_val_count = 0;

        while (i < eventCount && events[i].val == current_pos) {
            if (events[i].type == 0) active_ranges++;
            else if (events[i].type == -1) active_ranges--;
            else if (events[i].type == 1) current_val_count++;
            i++;
        }

        int can_change = active_ranges - current_val_count;
        int total = current_val_count + MIN(numOperations, can_change);
        max_freq = MAX(max_freq, total);
    }

    free(events);
    return max_freq;
}