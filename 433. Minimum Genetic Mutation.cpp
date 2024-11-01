class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankset(bank.begin(), bank.end());
        unordered_set<string> visited;
        queue<string> q;
        q.push(startGene);
        visited.insert(startGene);
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                string curr = q.front();
                q.pop();
                if(curr == endGene) return level;

                for(char c:"ACGT"){
                    for(int i = 0; i < curr.length(); i++){
                        string neighbor = curr;
                        neighbor[i] = c;
                        if(visited.find(neighbor) == visited.end() && bankset.find(neighbor) != bankset.end()){
                            visited.insert(neighbor);
                            q.push(neighbor);
                        }
                    }
                }
            }
            level+=1;
        }
        return -1;
    }   
};
