#include <stdio.h>
#include <math.h>

typedef long long ll;


int canReduce(ll mid, int mountainHeight, int* workerTimes, int workerTimesSize) {
    ll totalReduced = 0;
    for (int i = 0; i < workerTimesSize; i++) {
        ll t = workerTimes[i];
       
        ll x = (long long)((-1.0 + sqrt(1.0 + 8.0 * (double)mid / t)) / 2.0);
        totalReduced += x;
        
        if (totalReduced >= mountainHeight) return 1;
    }
    return totalReduced >= mountainHeight;
}

long long minNumberOfSeconds(int mountainHeight, int* workerTimes, int workerTimesSize) {
    ll low = 1;
    
    ll high = 1e16; 
    ll ans = high;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (canReduce(mid, mountainHeight, workerTimes, workerTimesSize)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
