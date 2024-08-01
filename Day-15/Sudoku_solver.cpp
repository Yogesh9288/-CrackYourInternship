class Solution {
private:
    bool solve(vector<vector<char>>& board, vector<vector<bool>>& rows,
               vector<vector<bool>>& cols, vector<vector<bool>>& box, int i,
               int j) {

        if (j == 9) {
            i++;
            j = 0;
        }
        if (i == 9)
            return true;
        if (board[i][j] == '.') {
            for (int k = 1; k <= 9; k++) {
                int idx = k;
                if (!rows[i][idx] && !cols[j][idx] &&
                    !box[(i / 3) * 3 + j / 3][idx]) {
                    rows[i][idx] = 1;
                    cols[j][idx] = 1;
                    box[(i / 3) * 3 + j / 3][idx] = 1;
                    board[i][j] = k + '0';
                    if (solve(board, rows, cols, box, i, j + 1))
                        return true;
                    rows[i][idx] = 0;
                    cols[j][idx] = 0;
                    box[(i / 3) * 3 + j / 3][idx] = 0;
                    board[i][j] = '.';
                }
            }

        } else
            return solve(board, rows, cols, box, i, j + 1);

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(10, 0));
        vector<vector<bool>> cols(9, vector<bool>(10, 0));
        vector<vector<bool>> box(9, vector<bool>(10, 0));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int idx = board[i][j] - '0';
                    rows[i][idx] = 1;
                    cols[j][idx] = 1;
                    box[(i / 3) * 3 + j / 3][idx] = 1;
                }
            }
        }
        solve(board, rows, cols, box, 0, 0);
    }
};
