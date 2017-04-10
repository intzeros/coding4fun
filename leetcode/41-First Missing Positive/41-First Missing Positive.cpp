class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()){
            if(nums[i] > 0 && nums[i]-1 < nums.size() && nums[i] != i+1 && nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }else{
                i++;
            }
        }
        
        i = 0;
        while(i < nums.size() && nums[i] == i+1) i++;
        return i+1;
    }
};
