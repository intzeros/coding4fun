class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string> > hashMap;
        for(int i = 0; i < n; i++){
            string s(strs[i]);
            sort(s.begin(), s.end());
            hashMap[s].push_back(strs[i]);  
        }
        
        vector<vector<string> > ans;
        unordered_map<string, vector<string> >::iterator it;
        for(it = hashMap.begin(); it != hashMap.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};
