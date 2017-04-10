class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(stk.empty()) stk.push(s.at(i));
            else{
                switch(s.at(i)){
                    case ')':
                        if(stk.top() == '('){
                            stk.pop();
                            break;
                        }
                    case ']':
                        if(stk.top() == '['){
                            stk.pop();
                            break;
                        }
                    case '}':
                        if(stk.top() == '{'){
                            stk.pop();
                            break;
                        }
                    default:
                        stk.push(s.at(i));
                }
            }
        }
        
        if(stk.empty()) return true;
        else return false;
    }
};
