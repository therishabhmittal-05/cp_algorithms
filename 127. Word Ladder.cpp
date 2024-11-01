class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<char> alphabet;
        for(int i = 0; i < 26; i++){
            alphabet.push_back('a' + i);
        }
        unordered_set<string> wordset(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        int level = 1;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                string curr = q.front();
                q.pop();
                if(curr == endWord) return level;

                for(char c: alphabet){
                    for(int i = 0; i < curr.length(); i++){
                        string neighbor = curr;
                        neighbor[i] = c;
                        if(visited.find(neighbor) == visited.end() && wordset.find(neighbor) != wordset.end()){
                            visited.insert(neighbor);
                            q.push(neighbor);
                        }
                    }
                }
            }
            level+=1;
        }
        return 0;
    }
};
