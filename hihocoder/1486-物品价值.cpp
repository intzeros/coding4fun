#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    int t, n, m, s, id;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<vector<int>> data(n+1, vector<int>());
        vector<int> val(n+1, 0);
        vector<vector<int>> dp(n+1, vector<int>(1<<m, 0x80000000));
        
        for(int i = 1; i <= n; i++){
            cin >> val[i] >> s;
            while(s--){
                cin >> id;
                data[i].push_back(id);
            }
        }
        
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++){
            int mask = 0;
            for(int k = 0; k < data[i].size(); k++){
                mask |= (1 << (data[i][k]-1));
            }
 
            for(int state = 0; state < (1<<m); state++){
                int pre = state ^ mask;
                dp[i][state] = max(dp[i-1][state], dp[i-1][pre] + val[i]);
            }
        }
        
        cout << dp[n][(1<<m)-1] << endl;
    }
    return 0;
}
