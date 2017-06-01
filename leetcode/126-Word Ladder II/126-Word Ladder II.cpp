class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size(), len = beginWord.size();
        unordered_set<string> wordSet;
        for(int i = 0; i < n; i++){
            wordSet.insert(wordList[i]);   
        }
        
        queue<string> Q;
        unordered_set<string> inq;
        Q.push(beginWord);
        inq.insert(beginWord);
        unordered_map<string, vector<string>> pres;
        bool ok = false;
        while(!Q.empty()){
            int m = Q.size();
            unordered_set<string> tmp_inq;
            for(int i = 0; i < m; i++){
                string now = Q.front();
                Q.pop();
                for(int k = 0; k < len; k++){
                    for(char c = 'a'; c <= 'z'; c++){
                        string next = now;
                        next[k] = c;
                        if(wordSet.find(next) == wordSet.end()) continue;
                        if(inq.find(next) != inq.end()) continue;
                        if(next == endWord) ok = true;
                        if(tmp_inq.find(next) == tmp_inq.end()){  //保证仅入队列一次
                            Q.push(next);
                            tmp_inq.insert(next);
                        }
                        pres[next].push_back(now);
                    }
                }
            }
            if(ok) break;
            for(auto it = tmp_inq.begin(); it != tmp_inq.end(); it++){
                inq.insert(*it);
            }
        }
        
        vector<vector<string>> rst_paths;
        if(!ok) return rst_paths;
        generate_paths(pres, rst_paths, endWord, vector<string>());
        return rst_paths;
    }
    
private:
    void generate_paths(unordered_map<string, vector<string>>& map, vector<vector<string>>& rst_paths, string& node, vector<string> path){
        
        path.push_back(node);
        vector<string> pre = map[node];
        int n = pre.size();
        if(n == 0){
            reverse(path.begin(), path.end());
            rst_paths.push_back(path);
            return;
        }
        
        for(int i = 0; i < n; i++){
            generate_paths(map, rst_paths, pre[i], path);
        }
    }
};
