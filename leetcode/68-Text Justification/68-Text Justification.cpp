class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> rst;
        int i = 0, n = words.size();
        while(i < n){
            int j = i+1, cnt = 1, sum = words[i].size();
            while(j < n && sum + words[j].size() + cnt <= maxWidth){
                sum += words[j].size();
                cnt++;
                j++;
            }
            
            string str = words[i];
            if(i+cnt == n){
                for(int k = i+1; k < j; k++){
                    str += " " + words[k];
                }
                str += string(maxWidth - sum - cnt + 1, ' ');
            }else if(cnt == 1){
                str += string(maxWidth - words[i].size(), ' ');
            }else {
                int m1 = (maxWidth - sum) / (cnt - 1);
                int m2 = (maxWidth - sum) % (cnt - 1);
                if(m1 != 0) m1++;
                
                for(int k = 1; k <= m2; k++){
                    str += string(m1, ' ') + words[k+i];
                }
                for(int k = 1; k <= (cnt-m2-1); k++){
                    str += string(m1-1, ' ') + words[k+i+m2];
                }
            }
            rst.push_back(str);
            i = j;
        }
        return rst;
    }
};
