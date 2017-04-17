class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1, i = digits.size()-1;
        while(i >= 0 && c){
            c = (digits[i] + 1) / 10;
            digits[i] = (digits[i] + 1) % 10;
            i--;
        }
        if(c) digits.insert(digits.begin(), 1);
        return digits;
    }
};
