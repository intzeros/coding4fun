class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int u = 0, d = n-1, l = 0, r = n-1, k = 1;
        while(true){
            for(int i = l; i <= r; i++) matrix[u][i] = k++;
            if(++u > d) break;
            for(int i = u; i <= d; i++) matrix[i][r] = k++;
            if(--r < l) break;
            for(int i = r; i >= l; i--) matrix[d][i] = k++;
            if(--d < u) break;
            for(int i = d; i >= u; i--) matrix[i][l] = k++;
            if(++l > r) break;
        }
        return matrix;
    }
};
