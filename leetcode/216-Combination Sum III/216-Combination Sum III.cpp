class Solution {
public:
    vector<vector<int>> rst;
    
    void DFS(int from, int k, int target, vector<int>& vec){
        if(target == 0){
            if(vec.size() == k) rst.push_back(vec);
            return;
        }
        
        for(int i = from; i <= 9; i++){
            if(target - i < 0) break;
            vec.push_back(i);
            DFS(i+1, k, target - i, vec);
            vec.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        DFS(1, k, n, *(new vector<int>()));
        return rst;
    }
};
