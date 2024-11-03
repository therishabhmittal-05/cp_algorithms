class Solution {
    // bool bfs(int src, unordered_map<int, vector<int>>& adjList, vector<int>& color){
    //     queue<int> q;
    //     q.push(src);
    //     color[src] = 1; // 1 = g_1, 0 = g_2
    //     while(!q.empty()){
    //         int node = q.front();
    //         q.pop();

    //         for(auto &it : adjList[node]){
    //             if(color[node] == color[it]) return false;
    //             if(color[it] == -1){
    //                 q.push(it);
    //                 color[it] = 1 - color[node];
    //             }
    //         }
    //     }
    //     return true;
    // }

    bool dfs(int src, unordered_map<int, vector<int>>& adjList, vector<int>& color){
        for(auto node: adjList[src]){
            if(color[node] == color[src]) return false;
            if(color[node] == -1){
                color[node] = 1- color[src];
                if(!dfs(node, adjList, color)) return false;
            }
        }
        return true;
    }
    // bool dfs(int src, unordered_map<int, vector<int>>& adjList, vector<int>& color) {
    //     for (auto node : adjList[src]) {
    //         if (color[node] == color[src]) return false; // Conflict found
    //         if (color[node] == -1) { // If the node is uncolored
    //             color[node] = 1 - color[src]; // Color with opposite color
    //             if (!dfs(node, adjList, color)) return false; // Propagate false
    //         }
    //     }
    //     return true;
    // }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> adjList;
        for(auto dislike: dislikes ){
            int u = dislike[0];  
            int v = dislike[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u); 
        }
        vector<int>color(n+1, -1);
        for(int i = 1; i <= n; i++){
            if(color[i] == -1){
                    color[i] = 1;
                if(!dfs(i, adjList, color)){
                    return false;
                }
                // if(bfs(i, adjList, color) == false){
                //     return false;
                // }
            }
        }
        return true;
    }
    // bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    //     unordered_map<int, vector<int>> adjList;
    //     // Build the adjacency list
    //     for (auto dislike : dislikes) {
    //         int u = dislike[0];
    //         int v = dislike[1];
    //         adjList[u].push_back(v);
    //         adjList[v].push_back(u);
    //     }

    //     vector<int> color(n + 1, -1); // -1 means uncolored

    //     // Process each node to handle all connected components
    //     for (int i = 1; i <= n; i++) {
    //         if (color[i] == -1) { // Unvisited node
    //             color[i] = 1; // Start coloring with color 1
    //             if (!dfs(i, adjList, color)) {
    //                 return false; // If any component is not bipartite
    //             }
    //         }
    //     }
    //     return true; // All components are bipartite
    // }
};
