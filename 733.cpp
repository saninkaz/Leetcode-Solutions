#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int sr, int sc, vector<vector<int>> &image, vector<vector<int>> &vis, int m, int n, int color, int originalColor)
    {
        vis[sr][sc] = 1;
        image[sr][sc] = color;

        for (int delrow = -1; delrow <= 1; delrow += 2)
        {
            int nrow = sr + delrow;
            if (nrow >= 0 && nrow < m && image[nrow][sc] == originalColor && !vis[nrow][sc])
            {
                image[nrow][sc] = color;
                dfs(nrow, sc, image, vis, m, n, color, originalColor);
            }
        }

        for (int delcol = -1; delcol <= 1; delcol += 2)
        {
            int ncol = sc + delcol;
            if (ncol >= 0 && ncol < n && image[sr][ncol] == originalColor && !vis[sr][ncol])
            {
                dfs(sr, ncol, image, vis, m, n, color, originalColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {

        int m = image.size();
        int n = image[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        int originalColor = image[sr][sc];

        dfs(sr, sc, image, vis, m, n, color, originalColor);

        return image;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> image1 = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};
    int sr1 = 1, sc1 = 1, color1 = 2;
    vector<vector<int>> result1 = sol.floodFill(image1, sr1, sc1, color1);

    cout << "Output Image 1:\n";
    for (auto row : result1)
    {
        for (auto val : row)
            cout << val << " ";
        cout << "\n";
    }

    vector<vector<int>> image2 = {
        {0, 0, 0},
        {0, 0, 0}};
    int sr2 = 0, sc2 = 0, color2 = 0;
    vector<vector<int>> result2 = sol.floodFill(image2, sr2, sc2, color2);

    cout << "\nOutput Image 2:\n";
    for (auto row : result2)
    {
        for (auto val : row)
            cout << val << " ";
        cout << "\n";
    }

    return 0;
}
