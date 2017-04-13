class Solution {
public:
    vector<vector<string>> rst;
    
    void DFS(int r, int n, vector<string> &sol, vector<bool> &cols, vector<bool> &diag1, vector<bool> &diag2){
        if(r == n){
            rst.push_back(sol);
            return;
        }
        for(int c = 0; c < n; c++){
            if(cols[c] || diag1[r+c] || diag2[r-c+n]) continue;
            cols[c] = diag1[r+c] = diag2[r-c+n] = true;
            sol[r][c] = 'Q';
            DFS(r+1, n, sol, cols, diag1, diag2);
            cols[c] = diag1[r+c] = diag2[r-c+n] = false;
            sol[r][c] = '.';
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> cols(n, false);
        vector<bool> diag1(2*n, false);
        vector<bool> diag2(2*n, false);
        vector<string> solution(n, string(n, '.'));
        DFS(0, n, solution, cols, diag1, diag2);
        return rst;
    }
};
