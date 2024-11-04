// 2 pass DFS
class Solution {
public:
    vector<int>cnt;
    int N;
    long root_res = 0;
    int dfs_base(unordered_map<int, vector<int>> &adjList, int curr, int parent, int curr_depth){
        int total_child = 1;
        root_res += curr_depth;

        for(auto &child: adjList[curr]){
            if(child != parent){
                total_child += dfs_base(adjList, child, curr, curr_depth+1);
            }
        }
        cnt[curr] = total_child;
        return total_child;
        
    }
    void DFS(vector<int> & result, unordered_map<int, vector<int>> & adjList, int curr, int parent){
        for(auto &child : adjList[curr]){
            if(child != parent){
             result[child] = result[curr] - cnt[child] + N - cnt[child];
             DFS(result, adjList, child, curr);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        cnt.assign(N, 0);
        root_res = 0;

        unordered_map<int, vector<int>> adjList;
        for(auto & edge: edges){
            adjList[edge[0]].push_back(edge[1]);                   
            adjList[edge[1]].push_back(edge[0]);                   
        }
        // 1st DFS to calculate the root dist sum and cnt vector
        dfs_base(adjList, 0, -1, 0);
        vector<int> result(n, 0);
        result[0] = root_res;
        // 2nd DFS to calculate result of all the nodes 
        DFS(result, adjList, 0, -1);
        return result;

    }
};

