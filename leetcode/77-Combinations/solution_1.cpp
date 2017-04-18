class Solution {
public:
    vector<vector<int> > rst;
    
    void solve(int n, int k, vector<int>& vec, int i){
        if(vec.size() == k){
            rst.push_back(vec);
            return;
        }
        if(n-i+1 < k-vec.size()) return; // 优化: 剩余元素个数小于 k
        
        vec.push_back(i);
        solve(n, k, vec, i+1);
        vec.pop_back();
        solve(n, k, vec, i+1);
    }
    
    vector<vector<int>> combine(int n, int k) {
        solve(n, k, *(new vector<int>()), 1);
        return rst;
    }
};
