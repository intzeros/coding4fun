class Solution {
public:
    int getVal(char c){
        switch(c){
            case 'M': return 1000;
            case 'D': return 500;
            case 'C': return 100;
            case 'L': return 50;
            case 'X': return 10;
            case 'V': return 5;
            case 'I': return 1;
        }
        return 0;
    }
 
    int romanToInt(string s) {
        int n = s.size();
        int ans = 0, i = 0;
 
        while(i < n){
            if(i+1 < n && getVal(s[i]) < getVal(s[i+1])){
                ans += getVal(s[i+1]) - getVal(s[i]);
                i+=2;
            }else{
                ans += getVal(s[i]);
                i++;
            }
        }
        return ans;
    }
};
