class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        while(x){
            ans = ans*10 + x%10;
            x /= 10;
        }
        
        int min = 0x80000000, max = 0x7fffffff;
        if(ans > max || ans < min){
            return 0;
        }
        return (int)ans;
    }
};
