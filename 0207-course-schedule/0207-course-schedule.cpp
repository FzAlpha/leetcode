class Solution {
public:
    bool iscycle(int scr ,vector<bool>& vis,vector<bool>& recPath , vector<vector<int>>& edges ){
        vis[scr] = true;
        recPath[scr] = true;

        for(int i =0 ;i< edges.size() ;i++){
            int v = edges[i][0];
            int u = edges[i][1];

            if(u == scr){
                if(!vis[v]){
                    if(iscycle(v,vis,recPath,edges)){
                        return true;
                    }
                }else if(recPath[v]){
                    return true;
                }
            }
        }
        recPath[scr] = false;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false);
        vector<bool> recPath(n,false);
        for(int i = 0 ; i<n;i++){
            if(!vis[i]){
                if(iscycle(i,vis,recPath,edges)){
                    return false;
                }
            }
        }
        return true;
    }
};