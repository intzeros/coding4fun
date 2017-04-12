class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        
        int n = num1.size(), m = num2.size();
        vector<int> rst(n+m, 0);
        for(int i = 0; i < n; i++){
            int c = 0;
            for(int j = 0; j < m; j++){
                int a = (num1[n-i-1]-'0') * (num2[m-j-1]-'0') + rst[i+j] + c;
                rst[i+j] = a % 10;
                c = a / 10;
            }
            
            if(c) rst[m+i] += c;
        }
        
        int end = n+m-1;
        while(end >= 0 && rst[end] == 0) end--;
        string ans = "";
        for(int i = end; i >= 0; i--){
            ans += rst[i] + '0';
        }
        return ans;
    }
};
