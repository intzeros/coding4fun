class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size(), m = b.size();
        if(n < m) return addBinary(b, a);
        
        string rst = string(max(n, m)+1, '0');
        int i = n-1, j = m-1, c = 0, k = max(n, m);
        while(j >= 0){
            int sum = a[i--]-'0' + b[j--]-'0' + c;
            if(sum >= 2) c = 1;
            else c = 0;
            rst[k--] = sum % 2 + '0';
        }
        while(i >= 0){
            int sum = a[i--]-'0'+c;
           if(sum >= 2) c = 1;
            else c = 0;
            rst[k--] = sum % 2 + '0';
        }
        if(c) rst[k--] = '1';
        return rst.substr(k+1);
    }
};
