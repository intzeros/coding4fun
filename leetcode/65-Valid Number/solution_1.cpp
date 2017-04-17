class Solution {
public:
    bool isInt(string s){
        if(s == "") return false;
        for(int i = 0; i < s.size(); i++){
            if(s[i] < '0' || s[i] > '9') return false;
        }
        return true;
    }
    
    bool isNumber(string s) {
        //去除前后空格
        int n = s.size();
        int i = 0, j = n-1;
        while(i < n && s[i] == ' ') i++;
        while(j >= i && s[j] == ' ') j--;
        s = s.substr(i).substr(0, j-i+1);
        
        if(s == "") return false;
        i = 0, n = s.size();
        if(s[0] == '-' || s[0] == '+') i++;
        
        j = i;
        while(j < n && (s[j] >= '0' && s[j] <= '9')) j++;
        if(j >= n){
            if(j == i) return false;    // "+" or "-"
            else return true;   // 纯数字
        }
        
        if(s[j] == '.'){
            if(j+1 == n){
                if(j == i) return false;    // "."
                else return true;   // "3."
            }
            
            int k = j+1;
            while(k < n && (s[k] >= '0' && s[k] <= '9')) k++;
            if(k >= n) return true;
            if(s[k] == 'e'){   // "3.e2" or // ".3e2"
                i++;
                j = k;
            }
        }
        
        if(s[j] == 'e'){
            if(j == i) return false;    //"e"前面必须有数字
            if(j+1 == n) return false;  //"e"之后必须有数字
            if(s[j+1] == '-' || s[j+1] == '+') j++;
            return isInt(s.substr(++j, n-j));
        }
        
        return false;
    }
};
