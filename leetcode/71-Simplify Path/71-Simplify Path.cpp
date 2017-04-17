class Solution {
public:
    string simplifyPath(string path) {
        vector<string> vec;
        int i = 1, n = path.size();
        while(i < n){
            int j = i;
            while(j < n && path[j] != '/') j++;
            string str = path.substr(i, j-i);
            if(str == "" || str == ".") {}
            else if(str == ".."){
                if(vec.size() > 0) vec.pop_back();
            } 
            else vec.push_back(str);
            i = ++j;
        }
        
        if(vec.size() == 0) return "/";
        string rst;
        for(int i = 0; i < vec.size(); i++){
            rst += "/" + vec[i];
        }
        return rst;
    }
};
