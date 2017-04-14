class Solution {
public:
    string getPermutation(int n, int k) {
        if(n == 0) return "0";
        
        int base = 1;
        for(int i = 2; i <= n; i++){ // base = n!
            base *= i;  
        }
        
        k--;
        string rst;
        vector<bool> used(n+1, false);
        for(int i = 0; i < n; i++){
            base /= (n-i);
            int a = k / base + 1;
            
            for(int j = 1, cnt = 0; j <= n; j++){
                if(used[j]) continue;
                else{
                    cnt++;
                    if(cnt == a){
                        rst += '0' + j;
                        used[j] = true;
                        break;
                    }
                }
            }
            k %= base;
        }
        return rst;
    }
};
