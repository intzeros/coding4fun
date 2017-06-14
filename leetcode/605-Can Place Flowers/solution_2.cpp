class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size(), k = 0;
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.insert(flowerbed.end(), 0);
        
        for(int i = 1; i <= size; i++){
            if(flowerbed[i] == 1) continue;
            if(flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                flowerbed[i] = 1;
                k++;
            }
        }
        return k >= n;
    }
};