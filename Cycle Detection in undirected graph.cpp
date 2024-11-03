class Solution {
  public:
    bool dfs(int src, int parent, vector<vector<int>>& adj, vector<bool>& visited){
        visited[src] = true;
        for(auto &node : adj[src]){
            if(!visited[node]){
                if(dfs(node, src, adj, visited)) return true;
            }
            else if (parent != node){
                return true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                if(dfs(i, -1, adj, visited)) return true;
            }
        }
        return false;
    }
};
