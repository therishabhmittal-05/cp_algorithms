class Solution {
public:
    // bool dfs(int source, int dest, unordered_map<int, vector<int>> &adjList,vector<bool>& visited){
    //     if(source == dest) return true;
    //     if(visited[source]) return false;
    //     visited[source] = true;
    //     for(auto& node : adjList[source]){
    //         if(dfs(node, dest, adjList, visited)){
    //             return true;
    //         }
    //     }
    //     return false;
    // }


    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // adj list
        unordered_map<int, vector<int>> adjList;
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        } 
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == destination) return true;  // Destination found

            for (auto &neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;  // Mark neighbor as visited
                }
            }
        }
        return false;
    }
};
