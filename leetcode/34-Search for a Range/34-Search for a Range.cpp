class Solution {
public:
    int find_start(vector<int>& nums, int low, int high, int target){
        int start = high;
        while(low <= high){
            int mid = (low+high)>>1;
            if(nums[mid] == target){
                if(mid < start) start = mid;
                high = mid-1;
            }else low = mid+1;
        }
        return start;
    }
    
    int find_end(vector<int>& nums, int low, int high, int target){
        int end = low;
        while(low <= high){
            int mid = (low+high)>>1;
            if(nums[mid] == target){
                if(mid > end) end = mid;
                low = mid+1;
            }else high = mid-1;
        }
        return end;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int start = -1, end = -1;
        while(low <= high){
            int mid = (low+high)>>1;
            if(nums[mid] == target){
                start = find_start(nums, low, mid, target);
                end = find_end(nums, mid, high, target);
                break;
            }else if(nums[mid] > target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        vector<int> ans;
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};
