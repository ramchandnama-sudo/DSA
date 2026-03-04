class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> result(n, -1);
        unordered_map<int, int> lakeFullDay;  // lake -> day it was filled
        set<int> dryDays;  // sorted set of available dry days
        
        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                // Dry day - we'll decide which lake to dry later
                dryDays.insert(i);
                result[i] = 1;  // Default: dry lake 1 (will be overwritten if needed)
            } else {
                int lake = rains[i];
                if (lakeFullDay.count(lake)) {
                    // Lake already full - need to find a dry day after it was filled
                    int lastFullDay = lakeFullDay[lake];
                    auto it = dryDays.upper_bound(lastFullDay);
                    
                    if (it == dryDays.end()) {
                        // No available dry day - flood is inevitable
                        return {};
                    }
                    
                    // Use this dry day to dry the lake
                    result[*it] = lake;
                    dryDays.erase(it);
                }
                // Mark lake as full on this day
                lakeFullDay[lake] = i;
            }
        }
        return result;
    }
};
