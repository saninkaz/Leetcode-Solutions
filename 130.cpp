#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void dfs(int sr, int sc, vector<vector<char>> &board, vector<vector<int>> &visited, int delrow[], int delcol[], int n, int m)
    {
        visited[sr][sc] = 1;
        for (int i = 0; i < 4; i++)
        {
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];

            if (nrow < n && ncol < m && nrow >= 0 && ncol >= 0 && board[nrow][ncol] == 'O' && visited[nrow][ncol] == 0)
            {

                dfs(nrow, ncol, board, visited, delrow, delcol, n, m);
            }
        }
    }

    void solve(vector<vector<char>> &board)
    {

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        int row[2] = {0, n - 1};
        int col[2] = {0, m - 1};
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, -1, 0, 1};

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[row[i]][j] == 'O')
                {
                    dfs(row[i], j, board, visited, delrow, delcol, n, m);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (board[i][col[j]] == 'O')
                {
                    dfs(i, col[j], board, visited, delrow, delcol, n, m);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main()
{
    // Example input
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}};

    Solution sol;
    sol.solve(board);

    // Output the result
    for (const auto &row : board)
    {
        for (char cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
