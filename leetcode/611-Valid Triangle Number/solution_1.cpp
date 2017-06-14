class Solution {
public:
    int bsearch(vector<int>& nums, int le, int ri, int sum){    
        int low = le, high = ri, mid;
        while(low <= high){
            mid = (low+high)>>1;
            if(sum > nums[mid]) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
    
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int k = bsearch(nums, j+1, n-1, nums[i]+nums[j]);
                ans += k-j-1;
            }
        }
        return ans;
    }
};