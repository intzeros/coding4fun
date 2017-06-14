class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 1, m = flowerbed.size(), k = 0;
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.insert(flowerbed.end(), 0);
        while(i <= m){
            if(flowerbed[i] == 1) i++;
            else{
                int cnt = 0;
                while(i <= m && flowerbed[i] == 0) cnt++, i++;
                if(flowerbed[i] == 0 && flowerbed[i-cnt-1] == 0) cnt += 2;
                else if(flowerbed[i] == 1 && flowerbed[i-cnt-1] == 0) cnt++;
                else if(flowerbed[i] == 0 && flowerbed[i-cnt-1] == 1) cnt++;
                
                k += (cnt+1)/2-1;
            }
        }
        return k >= n;
    }
};