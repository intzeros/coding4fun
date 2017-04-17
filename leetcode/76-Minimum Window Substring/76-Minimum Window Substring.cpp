class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> counts(256, 0);     // 统计T中每个字符的个数
        vector<int> counting(256, 0);    // 遍历S时，每个字符出现的次数
        for(int i = 0; i < m; i++){
            counts[t[i]]++;
        }
        
        int n_found = 0, start = 0, end = 0, minSize = 0x3f3f3f3f;
        string ans;
        for(; end < n; end++){
            int c = s[end];
            if(counts[c] == 0) continue;    // not in T
            
            counting[c]++;
            if(counting[c] <= counts[c]){
                n_found++;
            }
            
            if(n_found == m){    // 向后移动start指针
                while(counting[s[start]] > counts[s[start]] || counts[s[start]] == 0){
                    if(counting[s[start]] > counts[s[start]]) counting[s[start]]--;
                    start++;
                }
                
                if(end-start+1 < minSize){
                    minSize = end-start+1;
                    ans = s.substr(start, minSize);
                }
            }
        }
        return ans;
    }
};
