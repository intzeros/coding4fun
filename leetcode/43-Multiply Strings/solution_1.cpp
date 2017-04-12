class Solution {
public:
    string int2str(int num){
        stringstream ss;
        ss << num;
        return ss.str();
    }
    
    string add(string num1, string num2){
        if(num1.size() < num2.size()) swap(num1, num2);
        if(num2.size() == 0) return num1;
        
        string sum = "";
        int n = num1.size(), m = num2.size();
        int i, j, c = 0;
        for(i = n-1, j = m-1; i >= 0 && j >= 0; i--, j--){
            int a = num1[i] - '0' + num2[j] - '0' + c;
            if(a >= 10){
                c = 1;
                a %= 10;
            }else{
                c = 0;
            }
            sum = int2str(a) + sum;
        }
 
        if(c){
            return add(num1.substr(0, i+1), "1") + sum;
        }else{
            return num1.substr(0, i+1) + sum;
        }
    }
    
    string multiply_1bit(string num1, int b){
        string sum = "";
        int n = num1.size();
        int c = 0;
        for(int i = n-1; i >= 0; i--){
            int a = (num1[i]-'0') * b + c;
            if(a >= 10){
                c = a / 10;
                a %= 10;
            }else{
                c = 0;
            }
            sum = int2str(a) + sum;
        }
        if(c) return int2str(c) + sum; 
        else return sum;
    }
    
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        
        int n = num1.size(), m = num2.size();
        string ans = "0";
        for(int i = 0; i < m; i++){
            string tmp = multiply_1bit(num1, num2[i]-'0');
            if(ans != "0") ans += "0";
            ans = add(ans, tmp);
        }
        return ans;
    }
};
