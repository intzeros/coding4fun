class Solution {
public:
    int get_len(int x){
        int len = 0;
        while(x){
            x /= 10;
            len++;
        }
        return len;
    }
    
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x < 10) return true;
        
        int len = get_len(x);
        int n = pow(10, len-1);
        
        while(true){
            int a = x / n;
            int b = x % 10;
            if(a != b) return false;
            if(n < 100) break;
            x /= 10;
            n /= 10;
            x %= n;
            n /= 10;
        }
        return true;
    }
};
