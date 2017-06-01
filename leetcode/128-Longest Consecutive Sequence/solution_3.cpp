class Solution {
public:
    int getfa(int x, unordered_map<int, int>& fa){
        if(x != fa[x]){
            fa[x] = getfa(fa[x], fa);
        }
        return fa[x];
    }
    
    void unite(int x, int y, unordered_map<int, int>& fa){
        int fa1 = getfa(x, fa);
        int fa2 = getfa(y, fa);
        if(fa1 != fa2){
            fa[fa1] = fa2;
        }
    }
    
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> fa;
        for(int i = 0; i < n; i++){
            fa[nums[i]] = nums[i];
        }
        unordered_set<int> set(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(set.find(nums[i]-1) != set.end()) unite(nums[i]-1, nums[i], fa);
            if(set.find(nums[i]+1) != set.end()) unite(nums[i]+1, nums[i], fa);
        }
        
        unordered_map<int, int> cnts;
        for(auto it = set.begin(); it != set.end(); it++){ //为了去重
            cnts[getfa(*it, fa)]++;
        }
        
        int ans = 0;
        for(auto it = cnts.begin(); it != cnts.end(); it++){
            if(it->second > ans) ans = it->second;
        }
        return ans;
    }
};
