class Solution {
public:
    vector<vector<int>> rst;
    
    void DFS(int from, vector<int>& candidates, int target, vector<int>& vec){
        if(target == 0){
            rst.push_back(vec);
        }else{
            for(int i = from; i < candidates.size(); i++){
                if(target < candidates[i]) break;
                vec.push_back(candidates[i]);
                DFS(i, candidates, target - candidates[i], vec);
                vec.pop_back();
            }
        }
    }
 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        DFS(0, candidates, target, *(new vector<int>()));
        return rst;
    }
};
