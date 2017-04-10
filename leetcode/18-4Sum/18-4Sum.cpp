class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> rst;
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < n; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                
                int le = j+1, ri = n-1;
                while(le < ri){
                    int sum = nums[i] + nums[j] + nums[le] + nums[ri];
                    if(sum == target){
                        vector<int> vec;
                        vec.push_back(nums[i]);
                        vec.push_back(nums[j]);
                        vec.push_back(nums[le]);
                        vec.push_back(nums[ri]);
                        rst.push_back(vec);
                        
                        while(le < ri && nums[le] == nums[le+1]) le++;
                        while(le < ri && nums[ri] == nums[ri-1]) ri--;
                        le++, ri--;
                    }else if(sum < target) le++;
                    else ri--;
                }
            }
        }
        return rst;
    }
};
