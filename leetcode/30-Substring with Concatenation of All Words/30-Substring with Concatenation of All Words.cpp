class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size(), m = words.size(), len = words[0].size();
        unordered_map<string, int> counts;
        for(int i = 0; i < m; i++){
            counts[words[i]]++;
        }
        
        vector<int> rst;
        unordered_map<string, int> counting;
        for(int i = 0; i <= n - m*len; i++){
            counting.clear();
            int j = 0;
            for(; j < m; j++){
                string key = s.substr(i+j*len, len);
                if(counts.find(key) == counts.end()) break;
                counting[key]++;
                if(counting[key] > counts[key]) break;
            }
            if(j == m) rst.push_back(i);
        }
        return rst;
    }
};
