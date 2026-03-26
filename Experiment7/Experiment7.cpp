class Solution {
public: 
    int n = 0, m = 0;
    vector<int> x = {1, -1, 0, 0};
    vector<int> y = {0, 0, 1, -1};
    
    bool solve(vector<vector<char>>& board, int k , int r, int c, string word)
    {
        if(k == word.size()) return true;

        if(r < 0 || c < 0 || r >= n || c >= m || board[r][c] != word[k]) return false;

        char temp = board[r][c];
        board[r][c] = '!';

        for(int i = 0; i < 4; i++)
        {
            int nx = r + x[i];
            int ny = c + y[i];

            if(solve(board, k+1, nx, ny, word))
            {
                return true;
            }
            
        }
        board[r][c] = temp;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for(int i = 0; i <n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(solve(board, 0, i, j, word)) return true;
            }
        }
        return false;
    }
};