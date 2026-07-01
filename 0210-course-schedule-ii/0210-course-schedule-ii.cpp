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

    void tsort(int scr , vector<bool>& vis,stack<int> &s,vector<vector<int>>& edges){
        vis[scr] = true;
        for(int i =0 ;i< edges.size() ;i++){
            int v = edges[i][0];
            int u = edges[i][1];

            if(u == scr){
                if(!vis[v]){
                    tsort(v , vis , s , edges);
                }
            }
        }
        s.push(scr);
    }

    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false);
        vector<bool> recPath(n,false);
        vector<int> ans;
        for(int i = 0 ; i<n;i++){
            if(!vis[i]){
                if(iscycle(i,vis,recPath,edges)){
                    return ans;
                }
            }
        }
        stack<int> s;
        vis.assign(n,false);
        for(int i = 0 ; i<n;i++){
            if(!vis[i]){
                tsort(i,vis , s , edges);
            }
        }
        while(s.size()> 0){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};