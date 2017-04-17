class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;
        
        long long low = 2, high = x, mid;
        while(low <= high){
            mid = (low+high)>>1;
            long long d = mid*mid;
            if(x == d) return mid;
            else if(d < x) low = mid+1;
            else high = mid-1;
        }
        return high;
    }
};
