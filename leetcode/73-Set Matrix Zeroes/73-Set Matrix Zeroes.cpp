class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(); 
        if(n == 0) return;
        int m = matrix[0].size();
        int row = -1, col = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    if(row == -1){
                        row = i, col = j;
                    }
                    
                    matrix[row][j] = 0;
                    matrix[i][col] = 0;
                }
            }
        }
        
        if(row == -1) return;
        for(int i = 0; i < n; i++){
            if(i != row && matrix[i][col] == 0){
                for(int j = 0; j < m; j++){
                    if(j != col){
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        for(int j = 0; j < m; j++){
            if(j != col && matrix[row][j] == 0){
                for(int i = 0; i < n; i++){
                    if(i != row){
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        if(matrix[row][col] == 0){
            for(int i = 0; i < n; i++) matrix[i][col] = 0;
            for(int j = 0; j < m; j++) matrix[row][j] = 0;
        }
    }
};
