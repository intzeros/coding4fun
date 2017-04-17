class Solution {
public:
    bool binarySearch(vector<int>& nums, int target){
        int le = 0, ri = nums.size()-1, mid;
        while(le <= ri){
            mid = (le+ri)>>1;
            if(nums[mid] == target) return true;
            else if(nums[mid] < target) le = mid+1;
            else ri = mid-1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0) return false;
        int m = matrix[0].size();
        if(m == 0) return false;
        int low = 0, high = n-1, mid;
        while(low <= high){
            mid = (low+high)>>1;
            if(matrix[mid][0] <= target && target <= matrix[mid][m-1]){
                return binarySearch(matrix[mid], target);
            }else if(target > matrix[mid][m-1]){
                low = mid+1;
            }else if(target < matrix[mid][m-1]){
                high = mid-1;
            }
        }
        return false;
    }
};
