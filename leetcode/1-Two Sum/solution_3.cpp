class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> hashMap;   // <num, index>
        vector<int> rst;
        for(int i = 0; i < n; i++){
            if(hashMap.find(target - nums[i]) != hashMap.end()){
                rst.push_back(i);
                rst.push_back(hashMap[target - nums[i]]);
                return rst;
            }else{
                // hashMap.insert(make_pair(nums[i], i));
                hashMap[nums[i]] = i;
            }
        }
        return rst;
    }
};
