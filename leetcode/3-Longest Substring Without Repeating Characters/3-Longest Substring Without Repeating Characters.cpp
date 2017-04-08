class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> used(256, false);
        int cnt = 0, ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(used[s[i]] == false){
                used[s[i]] = true;
                cnt++;
                if(cnt > ans) ans = cnt;
            }else{
                int j = i-cnt;
                while(s[j] != s[i]){
                    used[s[j]] = false;
                    j++;
                }
                cnt = i-j;
            }
        }
        return ans;
    }
};
