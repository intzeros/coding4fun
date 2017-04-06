#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
 
int main(){
    int n, m;
    string s, tmp;
    cin >> n >> s;
    cin >> m;
    bool illegal[26][26];
    memset(illegal, false, sizeof(bool)*26*26);
    while(m--){
        cin >> tmp;
        illegal[tmp[0]-'a'][tmp[1]-'a'] = true;
        illegal[tmp[1]-'a'][tmp[0]-'a'] = true;
    }
    
    int dp[26];
    memset(dp, 0, sizeof(int)*26);
    dp[s[0]-'a'] = 1;
    
    for(int i = 1; i < n; i++){
        int cur = s[i]-'a';
        
        if(!illegal[cur][cur]) dp[cur]++;
        
        for(int a = 0; a < 26; a++){
            if(a == cur) continue;
            if(!illegal[a][cur]) dp[cur] = max(dp[cur], dp[a] + 1);
        }
    }
    
    int ans = 0;
    for(int i = 0; i < 26; i++){
        ans = max(ans, dp[i]);
    }
    cout << n-ans << endl;
    return 0;
}
