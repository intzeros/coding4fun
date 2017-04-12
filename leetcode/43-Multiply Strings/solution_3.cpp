class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        
        int n = num1.size(), m = num2.size();
        vector<int> rst(n+m, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                rst[i+j+1] += (num1[i]-'0') * (num2[j]-'0');
            }
        }
        
        string ans = "";
        for(int i = n+m-1; i >= 0; i--){
            if(i > 0) rst[i-1] += rst[i] / 10;
            ans = char(rst[i] % 10 + '0') + ans;
        }
        if(ans[0] == '0') return ans.substr(1);
        else return ans;
    }
};
