#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    int n_node, n_depth, n_leaf, x;
    cin >> n_node >> n_depth >> n_leaf;
    vector<int> cnt(n_depth+1);
    for(int i = 1; i <= n_depth; i++){
        cin >> cnt[i];
    }
    vector<vector<int>> level(n_depth+1, vector<int>());
    for(int i = 1; i <= n_depth; i++){
        for(int j = 0; j < cnt[i]; j++){
            cin >> x;
            level[i].push_back(x);
        }
    }
    vector<bool> is_leaf(n_node+1, false);
    vector<int> leaves(n_leaf);
    for(int i = 0; i < n_leaf; i++){
        cin >> leaves[i];
        is_leaf[leaves[i]] = true;
    }
    vector<vector<int>> dist(n_node+1, vector<int>(n_node+1, 0x3f3f3f3f));
    for(int i = 0; i < n_leaf; i++){
        for(int j = 0; j < n_leaf; j++){
            cin >> dist[leaves[i]][leaves[j]];
        }
    }
    
    vector<int> parents(n_node+1, -1);
    parents[level[1][0]] = 0;   // not parents[1] = 0
    
    for(int d = n_depth; d >= 2; d--){
        int fa = 0, cur = 0;
        while(cur < level[d].size()){
            while(fa < level[d-1].size() && is_leaf[level[d-1][fa]]) fa++;
            parents[level[d][cur]] = level[d-1][fa];
 
            int i = cur+1;
            while(i < level[d].size() && dist[level[d][cur]][level[d][i]] == 2){
                parents[level[d][i]] = parents[level[d][cur]];
                i++;
            }
            
            // update
            for(int j = 0; j < leaves.size(); j++){
                if(parents[leaves[j]] == level[d-1][fa]) continue;
                dist[level[d-1][fa]][leaves[j]] = dist[level[d][cur]][leaves[j]] - 1;
                dist[leaves[j]][level[d-1][fa]] = dist[level[d][cur]][leaves[j]] - 1;
            }
            is_leaf[level[d-1][fa]] = true;
            leaves.push_back(level[d-1][fa]);
            
            fa++;
            cur = i;
        }
    }
 
    for(int i = 1; i < n_node; i++){
        cout << parents[i] << " ";
    }
    cout << parents[n_node] << endl;
    return 0;
}
