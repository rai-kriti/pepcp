class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        
        deque<pair<int, pair<int, int>>> pq;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        
        int damage = grid[0][0];
        pq.push_front({damage, {0, 0}});
        dist[0][0] = damage;
        
        int r[] = {-1, 1, 0, 0};
        int c[] = {0, 0, -1, 1};
        
        while(!pq.empty()){
            int damage = pq.front().first;
            int x = pq.front().second.first;
            int y = pq.front().second.second;
            pq.pop_front();
            
            if(x == n - 1 && y == m - 1) {
                return damage < health;
            }
            
            if(damage > dist[x][y]) continue;
            
            for(int i = 0; i < 4; i++){
                int newX = x + r[i];
                int newY = y + c[i];
                
                if(newX >= 0 && newX < n && newY >= 0 && newY < m){
                    int new_damage = damage + grid[newX][newY];
                    
                    if(new_damage < dist[newX][newY] && new_damage < health){
                        dist[newX][newY] = new_damage;
                        
                        if(grid[newX][newY] == 0)
                            pq.push_front({new_damage, {newX, newY}});
                        else
                            pq.push_back({new_damage, {newX, newY}});
                    }
                }
            }
        }
        
        return false;
    }
};