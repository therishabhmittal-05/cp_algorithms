class Solution {
public:
    // vector<int> dfs(int curr, int parent,unordered_map<int, vector<int>> &adjList, string & labels,vector<int>& result){
    //     vector<int> cnt(26, 0);
    //     cnt[labels[curr] - 'a'] ++;
    //     for(auto & child: adjList[curr]){
    //         if(child != parent){
    //             vector<int> child_cnt = dfs(child, curr, adjList, labels, result);

    //             for(int i = 0; i < 26; i++){
    //                 cnt[i] += child_cnt[i];
    //             }
    //         }
    //     }
    //     result[curr] = cnt[labels[curr] - 'a'];
    //     return cnt;
    // }
    void dfs(int curr, int parent,unordered_map<int, vector<int>> &adjList, string & labels,vector<int>& result, vector<int>& cnt){
        char curr_char = labels[curr];
        int cnt_before = cnt[curr_char - 'a'];

        cnt[curr_char - 'a']+=1;
        for(auto & it: adjList[curr]){
            if(it != parent){
                dfs(it, curr, adjList, labels, result, cnt);
            }
        }
        int cnt_after = cnt[curr_char - 'a'];
        result[curr] = cnt_after - cnt_before;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, vector<int>> adjList;
        for(auto& edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<int> result(n , 0);
        vector<int> cnt(26 , 0);
        dfs(0, -1, adjList, labels, result, cnt);
        return result;
    }
};
