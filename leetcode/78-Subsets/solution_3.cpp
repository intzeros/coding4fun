class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> rst;
        int n = nums.size();
        for(int i = 0; i < (1<<n); i++){
            vector<int> vec;
            for(int k = 0; k < n; k++){
                if((i>>k)&1){
                    vec.push_back(nums[k]);
                }
            }
            rst.push_back(vec);
        }
        return rst;
    }
};
