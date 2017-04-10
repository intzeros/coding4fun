class Solution {
public:
    string countAndSay(int n) {
        n--;
        string pre = "1";
        while(n--){
            string str = "";
            int i = 0;
            while(i < pre.size()){
                char pre_c = pre[i];
                int cnt = 1;
                while(i+cnt < pre.size() && pre[i+cnt] == pre_c) cnt++;
                str += to_string(cnt*10+pre_c-'0');
                i += cnt;
            }
            pre = str;
        }
        return pre;
    }
};
