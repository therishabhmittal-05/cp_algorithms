class Solution {
    
public:
    int dfs(int curr, int parent, vector<bool>& hasApple, unordered_map<int, vector<int>> &adjList){
        int time = 0;
        for(auto& it: adjList[curr]){
            if(it != parent){
                int time_from_it = dfs(it, curr, hasApple, adjList);
                if(time_from_it > 0 || hasApple[it]){
                    time += 2 + time_from_it;
                }
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> adjList;
        for(auto& edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        return dfs(0,-1,  hasApple, adjList);
    }
};
