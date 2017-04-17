class Solution {
public:
    int mySqrt(int x) {
        double pre = 1, rst;
        while(true){
            rst = (x/pre + pre) / 2;
            if(rst == pre || abs(rst-pre) < 0.0001) return (int)rst;
            pre = rst;
        }
    }
};
