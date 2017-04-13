class Solution {
public:
    bool next_permutation(vector<int>& nums){
        int n = nums.size();
        if(n == 1) return false;
        
        int i = n-2;
        while(i >= 0 && nums[i] >= nums[i+1]) i--;
            
        if(i < 0){
            return false;
        }
        
        int j = i+1;
        while(j < n && nums[j] > nums[i]) j++;
        swap(nums[i], nums[--j]);
        reverse(nums.begin()+i+1, nums.end());
        return true;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > rst;
        sort(nums.begin(), nums.end());
        rst.push_back(nums);
        
        while(true){
            vector<int> vec(rst.back());
            if(next_permutation(vec)){
                rst.push_back(vec);
            }else break;
        }
        return rst;
    }
};
