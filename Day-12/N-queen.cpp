class Solution {
private:
    //for checking diagonals
    bool check(vector<string>& board, int r, int c, int n) {
        int i = r, j = c;

        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }

        i = r, j = c;
        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q')
                return false;
            i--;
            j++;
        }

        return true;
    }

    //for finding appropriate position in the board
    void find(int n, vector<vector<string>>& ans, vector<string>& board,
              vector<bool>& col, int r) {
        if (r == n) {
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (col[i] == 0 && check(board, r, i, n)) {
                col[i] = 1;
                board[r][i] = 'Q';
                find(n, ans, board, col, r + 1);
                col[i] = 0;
                board[r][i] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i].push_back('.');
            }
        }

        vector<bool> col(n, 0);

        find(n, ans, board, col, 0);

        return ans;
    }
};
