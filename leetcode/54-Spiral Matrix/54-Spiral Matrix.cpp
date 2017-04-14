class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> rst;
        int n = matrix.size();
        if(n == 0) return rst;
        int m = matrix[0].size();
        
        int u = 0, d = n-1, l = 0, r = m-1;
        while(true){
            for(int i = l; i <= r; i++) rst.push_back(matrix[u][i]);
            if(++u > d) break;
            for(int i = u; i <= d; i++) rst.push_back(matrix[i][r]);
            if(--r < l) break;
            for(int i = r; i >= l; i--) rst.push_back(matrix[d][i]);
            if(--d < u) break;
            for(int i = d; i >= u; i--) rst.push_back(matrix[i][l]);
            if(++l > r) break;
        }
        return rst;
    }
};
