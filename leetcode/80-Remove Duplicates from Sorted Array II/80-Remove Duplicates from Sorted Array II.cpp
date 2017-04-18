class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i >= 2 && nums[i] == nums[i-2-k]) k++;
            else nums[i-k] = nums[i];
        }
        return nums.size()-k; 
    }
};
