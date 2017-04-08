class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> rst;
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue; //去重
            
            int target = -nums[i];
            int le = i+1, ri = n-1;   //twoSum的查找范围为[i+1, n)
            while(le < ri){
                if(nums[le] + nums[ri] == target){
                    vector<int> vec;
                    vec.push_back(nums[le]);
                    vec.push_back(nums[ri]);
                    vec.push_back(nums[i]);
                    rst.push_back(vec);
                    
                    while(le < ri && nums[le] == nums[le+1]) le++;  //去重
                    while(le < ri && nums[ri] == nums[ri-1]) ri--;
                    le++, ri--;
                }else if(nums[le] + nums[ri] < target) le++;
                else ri--;
            }
        }
        return rst;
    }
};
