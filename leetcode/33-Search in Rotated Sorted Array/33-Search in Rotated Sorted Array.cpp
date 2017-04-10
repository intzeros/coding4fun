class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        
        int low = 0, high = nums.size()-1, mid;
        while(low <= high){
            mid = (low+high)>>1;
            if(nums[mid] == target) return mid;
            
            if(low == mid || nums[low] < nums[mid]){    //前半段递增
                if(nums[low] <= target && target < nums[mid]) high = mid-1;
                else low = mid+1;
            }else{  //后半段递增
                 if(nums[mid] < target && target <= nums[high]) low = mid+1;
                 else high = mid-1;
            }
        }
        return -1;
    }
};
