class Solution {
public:
    int trap(vector<int>& height) {
        int le = 0, ri = height.size()-1, ans = 0, h = 0;
        while(le < ri){
            if(height[le] < height[ri]){
                if(height[le] > h) h = height[le];
                ans += h - height[le];
                le++;
            }else{
                if(height[ri] > h) h = height[ri];
                ans += h - height[ri];
                ri--;
            }
        }
        return ans;
    }
};
