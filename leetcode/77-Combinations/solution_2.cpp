class Solution {
public:
    vector<vector<int> > rst;
    
    void solve(int n, int k, vector<int>& vec, int from){
        if(k == 0){
            rst.push_back(vec);
            return;
        }
        for(int i = from; i <= n; i++){
            vec.push_back(i);
            solve(n, k-1, vec, i+1);
            vec.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        solve(n, k, *(new vector<int>()), 1);
        return rst;
    }
};
