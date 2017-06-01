class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size(), len = beginWord.size();
        unordered_set<string> wordSet;
        for(int i = 0; i < n; i++){
            wordSet.insert(wordList[i]);
        }
        
        if(wordSet.find(endWord) == wordSet.end()) return 0;
        
        queue<string> Q1, Q2;
        unordered_set<string> inq1, inq2;
        Q1.push(beginWord);
        Q2.push(endWord);
        inq1.insert(beginWord);
        inq2.insert(endWord);
        int rst = 1;
        while(!Q1.empty() && !Q2.empty()){
            queue<string> &Q = Q1.size() < Q2.size() ? Q1 : Q2;
            unordered_set<string> &pinq1 = Q1.size() < Q2.size() ? inq1 : inq2;
            unordered_set<string> &pinq2 = Q1.size() >= Q2.size() ? inq1 : inq2;
            int m = Q.size();
            rst++;
            for(int i = 0; i < m; i++){
                string now = Q.front();
                Q.pop();
                for(int k = 0; k < len; k++){
                    for(char c = 'a'; c <= 'z'; c++){
                        string next = now;
                        next[k] = c;
                        if(wordSet.find(next) == wordSet.end()) continue;
                        if(pinq2.find(next) != pinq2.end()) return rst;
                        if(pinq1.find(next) == pinq1.end()){
                            pinq1.insert(next);
                            Q.push(next);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
