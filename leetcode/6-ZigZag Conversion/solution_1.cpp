class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        
        int n = s.size();
        int T = (numRows<<1)-2;
        string rst;
 
        for(int r = 0; r < numRows; r++){
          int idx = r;
        	while(idx < n){
        		rst += s[idx];
        		if(r != 0 && r != numRows-1){
        			int idx2 = idx + T-2*r;
        			if(idx2 < n){
        				rst += s[idx2];
        			}
        		}
        		idx += T;
        	}
        }
        return rst;
    }
};
