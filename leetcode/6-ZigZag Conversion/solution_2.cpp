class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        
        int n = s.size();
        string rst[numRows];
 
        int i = 0;
        while(i < n){
            for(int r = 0; r < numRows && i < n; r++){   //竖直向下方向
                rst[r] += s[i++];
            }
            for(int r = numRows-2; r > 0 && i < n; r--){   //斜向上方向
                rst[r] += s[i++];
            }
        }
 
        string ans;
        for(int r = 0; r < numRows; r++){
        	ans += rst[r];
        }
        return ans;
    }
}
