class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>&result, vector<int>&temp, int source, int target){
        temp.push_back(source);
        if(source == target){
            result.push_back(temp);
        }
        else{
            for(auto & it: graph[source]){
                dfs(graph, result, temp, it, target);
            }
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> temp;
        int n = graph.size();
        dfs(graph, result, temp, 0, n-1);
        return result;
    }
};
