class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]) k++;
            else nums[i-k] = nums[i];
        }
        return nums.size() - k;
    }
};
