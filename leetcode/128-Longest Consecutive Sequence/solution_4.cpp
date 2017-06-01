class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), ans = 0;
    	unordered_map<int, int> map;
    	unordered_set<int> vis;
    	for(int x : nums){
    	    if(vis.find(x) != vis.end()) continue;
    	    vis.insert(x);
    	    
    	    int len = map[x-1] + map[x+1] + 1;
    	    if(len > ans) ans = len;
    	    map[x - map[x-1]] = len;
    	    map[x + map[x+1]] = len;
    	}
    	return ans;
    }
};
