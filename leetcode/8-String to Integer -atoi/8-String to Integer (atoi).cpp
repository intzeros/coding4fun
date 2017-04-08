class Solution {
public:
    int myAtoi(string str) {
        int n = str.size();
        int is_positive = 1;
        
        int i = 0;
        while(i < n && str[i] == ' ') i++;
        if(i == n) return 0;
        
        if(str[i] == '-'){
            is_positive = -1;
            i++;
        }else if(str[i] == '+') i++;
        
        if(str[i] > '9' || str[i] < '0') return 0;
        
        long long ans = 0;
        int m = 0;
        while(i < n && m < 12){
            //if(str[i] == ' ') i++;
            if(str[i] > '9' || str[i] < '0') break;
            ans = ans*10 + str[i++]-'0';
            m++;
        }
        ans *= is_positive;
        
        int min = 0x80000000, max = 0x7fffffff;
        if(ans < min) return min;
        if(ans > max) return max;
        
        return (int)ans;
    }
};
