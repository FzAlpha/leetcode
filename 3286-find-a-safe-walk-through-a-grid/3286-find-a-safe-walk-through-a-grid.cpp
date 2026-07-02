class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({-grid[0][0],{0,0}});
        vis[0][0] = true;
        int distR[] = {-1,1,0,0};
        int distC[] = {0,0,-1,1};
        while(pq.size()>0){
            int damage = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if(r == n-1 && c == m-1 && (damage*(-1)) < health){
                return true;
            }
            for(int i =0 ; i< 4 ; i++){
                int nr = r+distR[i];
                int nc = c+distC[i];
                if(nr>= 0 && nr<n && nc>= 0 && nc<m && !vis[nr][nc]){
                    int newdamage = (damage* (-1)) + grid[nr][nc];
                    if(newdamage < health){
                        vis[nr][nc] = true;
                        pq.push({-newdamage, {nr, nc}});
                    }
                }
            }

        }
        return false;

    }
};