// Last updated: 10/12/2026, 9:50:57 PM
class Solution {
public:
    void dfs(int curr, int& nodes, int& edges, vector<vector<int>>& adj,
             vector<bool>& visited) {
        nodes++;
        visited[curr] = true;
        for (int& n : adj[curr]) {
            edges++;
            if (!visited[n]) {
                dfs(n, nodes, edges, adj, visited);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int completeComponents = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int e = 0;
                int n = 0;
                dfs(i, n, e, adj, visited);

                if (e == (n * (n - 1))) {
                    completeComponents++;
                }
            }
        }
        return completeComponents;
    }
};