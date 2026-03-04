
int compareInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}


int findFirstValid(int* potions, int potionsSize, long long spell, long long success) {
    int left = 0, right = potionsSize - 1;
    int result = potionsSize;  
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if ((long long)spell * potions[mid] >= success) {
            result = mid;
            right = mid - 1; 
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, 
                     long long success, int* returnSize) {
    
    qsort(potions, potionsSize, sizeof(int), compareInt);
    
    int* result = (int*)malloc(spellsSize * sizeof(int));
    *returnSize = spellsSize;
    
    for (int i = 0; i < spellsSize; i++) {
        
        int idx = findFirstValid(potions, potionsSize, spells[i], success);
       
        result[i] = potionsSize - idx;
    }
    
    return result;
}