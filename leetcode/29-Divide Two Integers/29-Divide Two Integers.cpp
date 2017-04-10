class Solution {
public:
    int divide(int dividend, int divisor) {
        int MAX_INT = 0x7fffffff;
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long c = 1;
        while(a >= b){
            b <<= 1;
            c <<= 1;
        }
        
        long long ans = 0;
        while(c){
            c >>= 1;
            b >>= 1;
            if(a >= b){
                a -= b;
                ans += c;
            }
        }
        if(dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0) ans = -ans;
        if(ans > MAX_INT) return MAX_INT;
        return ans;
    }
};
