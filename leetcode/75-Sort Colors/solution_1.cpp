class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3];
        cnt[0] = cnt[1] = cnt[2] = 0;
        for(int i = 0; i < nums.size(); i++){
            cnt[nums[i]]++;
        }
        
        for(int i = 0, k = 0; i < 3; i++){
            while(cnt[i]--){
                nums[k++] = i;
            }
        }
    }
};
