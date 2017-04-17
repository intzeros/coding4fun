class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0) return false;
        int m = matrix[0].size();
        int le = 0, ri = n*m-1, mid;
        while(le <= ri){
            mid = (le+ri)>>1;
            if(matrix[mid/m][mid%m] == target) return true;
            else if(target > matrix[mid/m][mid%m]) le = mid+1;
            else ri = mid-1;
        }
        return false;
    }
};
