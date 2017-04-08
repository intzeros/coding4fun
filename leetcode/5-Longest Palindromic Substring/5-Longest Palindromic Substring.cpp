class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> isp(n, vector<bool>(n, false));
        int start = 0, len = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j >= 0; j--){
                if(s[i] == s[j] && (i-j <= 2 || isp[j+1][i-1])){
                    isp[j][i] = true;
                    if(i-j+1 > len) len = i-j+1, start = j;
                }
            }
        }
        return s.substr(start, len);
    }
};
