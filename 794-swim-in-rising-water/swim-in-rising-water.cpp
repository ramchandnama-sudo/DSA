class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        
        int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int result = 0;
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int elev = curr[0], r = curr[1], c = curr[2];
            result = max(result, elev);  
            
            
            if (r == n - 1 && c == n - 1) {
                return result;
            }
            
           
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    pq.push({grid[nr][nc], nr, nc});
                }
            }
        }
        return result;
    }
};