#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int *parent;
    int components;
} DSU;

int find(DSU *dsu, int i) {
    if (dsu->parent[i] == i) return i;
    return dsu->parent[i] = find(dsu, dsu->parent[i]);
}

bool unite(DSU *dsu, int i, int j) {
    int root_i = find(dsu, i);
    int root_j = find(dsu, j);
    if (root_i != root_j) {
        dsu->parent[root_i] = root_j;
        dsu->components--;
        return true;
    }
    return false;
}

// X ਸਥਿਰਤਾ ਚੈੱਕ ਕਰਨ ਲਈ ਫੰਕਸ਼ਨ
bool check(long long X, int n, int** edges, int edgesSize, int k) {
    DSU dsu;
    dsu.parent = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) dsu.parent[i] = i;
    dsu.components = n;

    int upgrades_used = 0;

    // 1. ਸਾਰੇ Must-include ਕਿਨਾਰੇ ਜੋੜੋ (musti == 1)
    for (int i = 0; i < edgesSize; i++) {
        if (edges[i][3] == 1) {
            // ਜੇਕਰ ਕਿਸੇ Must-include ਕਿਨਾਰੇ ਦੀ ਤਾਕਤ X ਤੋਂ ਘੱਟ ਹੈ, ਤਾਂ ਇਹ ਸਥਿਰਤਾ ਸੰਭਵ ਨਹੀਂ
            if (edges[i][2] < X) {
                free(dsu.parent);
                return false;
            }
            // ਜੇਕਰ must-include ਕਿਨਾਰੇ ਸਾਈਕਲ ਬਣਾਉਂਦੇ ਹਨ, ਤਾਂ ਇਹ MST ਨਹੀਂ ਬਣ ਸਕਦਾ
            if (!unite(&dsu, edges[i][0], edges[i][1])) {
                // ਕੇਸ 3 ਲਈ ਇਹ ਮਹੱਤਵਪੂਰਨ ਹੈ
                free(dsu.parent);
                return false; 
            }
        }
    }

    // 2. ਉਹ ਵਿਕਲਪਿਕ (Optional) ਕਿਨਾਰੇ ਜੋ ਪਹਿਲਾਂ ਹੀ >= X ਹਨ
    for (int i = 0; i < edgesSize; i++) {
        if (edges[i][3] == 0 && edges[i][2] >= X) {
            unite(&dsu, edges[i][0], edges[i][1]);
        }
    }

    // 3. ਉਹ ਵਿਕਲਪਿਕ ਕਿਨਾਰੇ ਜੋ ਅੱਪਗ੍ਰੇਡ ਤੋਂ ਬਾਅਦ >= X ਬਣਦੇ ਹਨ
    for (int i = 0; i < edgesSize; i++) {
        if (edges[i][3] == 0 && edges[i][2] < X && (long long)edges[i][2] * 2 >= X && upgrades_used < k) {
            if (unite(&dsu, edges[i][0], edges[i][1])) {
                upgrades_used++;
            }
        }
    }

    bool possible = (dsu.components == 1);
    free(dsu.parent);
    return possible;
}

int maxStability(int n, int** edges, int edgesSize, int* edgesColSize, int k) {
    // ਸਭ ਤੋਂ ਪਹਿਲਾਂ ਚੈੱਕ ਕਰੋ ਕਿ ਕੀ Must-include ਕਿਨਾਰੇ ਆਪਸ ਵਿੱਚ ਸਾਈਕਲ ਬਣਾਉਂਦੇ ਹਨ (stability = 0 'ਤੇ)
    // ਜੇਕਰ ਇੱਥੇ false ਆਉਂਦਾ ਹੈ, ਤਾਂ ਮਤਲਬ ਕੇਸ 3 ਵਰਗੀ ਸਥਿਤੀ ਹੈ।
    if (!check(0, n, edges, edgesSize, k)) return -1;

    long long low = 0, high = 2000000000, ans = 0;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid, n, edges, edgesSize, k)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return (int)ans;
}
