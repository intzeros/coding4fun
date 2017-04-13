class Solution {
public:
    double solve(double x, long long n){
        double rst = 1;
        while(n){
            if(n&1) rst *= x;
            x *= x;
            n >>= 1;
        }
        return rst;
    }
    
    double myPow(double x, int n) {
        long long m = n;
        if(m < 0) return 1.0 / solve(x, -m);
        else return solve(x, m);
    }
};
