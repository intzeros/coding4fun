class Solution {
public:
    int maxArea(vector<int>& height) {
        int le = 0, ri = height.size()-1, ans = 0;
        while(le < ri){
            int area = min(height[le], height[ri]) * (ri-le);
            if(area > ans) ans = area;
            
            if(height[le] < height[ri]) le++;
            else ri--;
         }
         return ans;
    }
};
