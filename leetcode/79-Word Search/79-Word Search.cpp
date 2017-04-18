class Solution {
public:
    int n, m;
    
    bool DFS(int x, int y, int i, vector<vector<char>>& board, string& word){
        if(x < 0 || x >= n || y < 0 || y >= m) return false;
        if(board[x][y] == '\0' || board[x][y] != word[i]) return false;
        if(i == word.size()-1) return true;
        
        char c = board[x][y];
        board[x][y] = '\0';
        
        if(DFS(x+1, y, i+1, board, word) || DFS(x-1, y, i+1, board, word) || DFS(x, y+1, i+1, board, word) || DFS(x, y-1, i+1, board, word)) return true;
        
        board[x][y] = c;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() == 0) return true;
        n = board.size();
        if(n == 0) return false;
        m = board[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0] && DFS(i, j, 0, board, word)){
                    return true;
                }
            }
        }
        return false;
    }
};
