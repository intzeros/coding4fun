class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int le = 0, ri = nums.size()-1, mid;
        while(le <= ri){
            mid = (le+ri)>>1;
            if(nums[mid] == target) return true;
            
            if(nums[le] == nums[mid] && nums[mid] == nums[ri]) le++, ri--;
            else if(nums[le] <= nums[mid]){
                if(nums[le] <= target && target <= nums[mid]) ri = mid-1;
                else le = mid+1;
            }else{
                if(nums[mid] <= target && target <= nums[ri]) le = mid+1;
                else ri = mid-1;
            }
        }
        return false;
    }
};
