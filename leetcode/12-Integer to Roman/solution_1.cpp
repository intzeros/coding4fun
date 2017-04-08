class Solution {
public:
    string C[8] = {"", "M", "D", "C", "L", "X", "V", "I"};
    int  D[8] = {5000, 1000, 500, 100, 50,  10,  5,   1 };
 
    string intToRoman(int num) {
        string ans = "";
 
        for(int i = 1; i <= 7; i++){
            int a = num / D[i];
            if(a == 0) continue;
        
            if((i&1) && D[i-1] - num <= D[i]){
                ans += C[i] + C[i-1];
                num -= (D[i-1] - D[i]);
            }else if(!(i&1) && D[i-1] - num <= D[i+1]){
                ans += C[i+1] + C[i-1];
                num -= (D[i-1] - D[i+1]);
            }else{
                while(a--){
                    ans += C[i];
                    num -= D[i];
                }
            }
        }
        return ans;
    }
};
