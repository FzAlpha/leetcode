class Solution {
public:
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return 0;
        }
        vector<vector<int>> distmap(n,vector<int>(n,-1));
        queue<pair<int,int>> q;

        for(int i =0 ; i<n;i++){
            for(int j = 0; j<n;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    distmap[i][j] =0;
                }
            }
        }
        int distR[] = {-1,1,0,0};
        int distC[] = {0,0,-1,1};

        while(q.size() > 0){
            int r= q.front().first;
            int c =q.front().second;
            q.pop();
            for(int i =0;i<4;i++){
                int nr = r+distR[i];
                int nc = c+distC[i];
                if(nr>= 0 && nr < n && nc >= 0 && nc<n && distmap[nr][nc] == -1){
                    distmap[nr][nc] = distmap[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }

        priority_queue<pair<int,pair<int,int>>> pq;
        vector<vector<bool>> vis(n,vector<bool>(n,false));

        pq.push({distmap[0][0],{0,0}});
        vis[0][0] = true;

        while(pq.size() > 0){
            int safe = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if(r == n-1 && c == n-1){
                return safe;
            }
            for(int i =0;i<4;i++){
                int nr = r+distR[i];
                int nc = c+distC[i];
                if(nr>= 0 && nr < n && nc >= 0 && nc<n && !vis[nr][nc]){
                    vis[nr][nc] = true;
                    int minSafe = min(safe,distmap[nr][nc]);
                    pq.push({minSafe,{nr,nc}});
                }
            }

        }
        return 0;
    }
};