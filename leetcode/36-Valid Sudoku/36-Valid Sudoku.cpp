class Solution {
public:
    bool check_33(vector<vector<char>>& board, int x, int y){
        bool used[10];
        memset(used, false, sizeof(bool)*10);
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i+x][j+y] == '.') continue;
                if(used[board[i+x][j+y]-'0']) return false;
                else used[board[i+x][j+y]-'0'] = true;
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        bool used[10];
        for(int i = 0; i < 9; i++){
            memset(used, false, sizeof(bool)*10);
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                if(used[board[i][j]-'0']){
                    return false;
                }else{
                    used[board[i][j]-'0'] = true;
                }
            }
        }
        
        for(int j = 0; j < 9; j++){
            memset(used, false, sizeof(bool)*10);
            for(int i = 0; i < 9; i++){
                if(board[i][j] == '.') continue;
                if(used[board[i][j]-'0']){
                    return false;
                }else{
                    used[board[i][j]-'0'] = true;
                }
            }
        }
        
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(check_33(board, i*3, j*3) == false) return false;
            }
        }
        return true;
    }
};
