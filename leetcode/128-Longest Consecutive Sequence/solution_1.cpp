class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        unordered_set<int> set(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++){
            if(set.find(nums[i]) == set.end()) continue;
            
            set.erase(nums[i]);
            int x = nums[i]-1, y = nums[i]+1, len = 1;
            while(set.find(x) != set.end()){
                set.erase(x);
                x--, len++;
            }
            while(set.find(y) != set.end()){
                set.erase(y);
                y++, len++;
            }
            if(len > ans) ans = len;
        }
        return ans;
    }
};
