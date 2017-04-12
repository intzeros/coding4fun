class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int max_idx = 0;
        for(int i = 0; i < n; i++){
            if(height[max_idx] < height[i]){
                max_idx = i;
            }
        }
        
        int h = 0, ans = 0;
        for(int i = 0; i < max_idx; i++){
            if(height[i] > h) h = height[i];
            ans += h - height[i];
        }
        
        h = 0;
        for(int j = n-1; j > max_idx; j--){
            if(height[j] > h) h = height[j];
            ans += h - height[j];
        }
        return ans;
    }
};
