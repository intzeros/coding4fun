class Solution {
public:
    void DFS(int r, int n, int& ans, vector<bool> &cols, vector<bool> &diag1, vector<bool> &diag2){
        if(r == n){
            ans++;
            return;
        }
        for(int c = 0; c < n; c++){
            if(cols[c] || diag1[r+c] || diag2[r-c+n]) continue;
            cols[c] = diag1[r+c] = diag2[r-c+n] = true;
            DFS(r+1, n, ans, cols, diag1, diag2);
            cols[c] = diag1[r+c] = diag2[r-c+n] = false;
        }
    }
    
    int totalNQueens(int n) {
        vector<bool> cols(n, false);
        vector<bool> diag1(2*n, false);
        vector<bool> diag2(2*n, false);
        int ans = 0;
        DFS(0, n, ans, cols, diag1, diag2);
        return ans;
    }
};
