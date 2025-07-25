#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
private:
    vector<int> previousSmallerElement(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> res;
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (st.size() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                res.push_back(-1);
            }
            else
            {
                res.push_back(st.top());
            }
            st.push(i);
        }

        return res;
    }

    vector<int> nextSmallerElement(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> res(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (st.size() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                res[i] = n;
            }
            else
            {
                res[i] = st.top();
            }
            st.push(i);
        }

        return res;
    }

public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {

        int n = matrix.size();
        int m = matrix[0].size();
        int mx = 0;

        vector<vector<int>> prefixSum(n, vector<int>(m));

        for (int j = 0; j < m; j++)
        {
            prefixSum[0][j] = matrix[0][j] - '0';
            for (int i = 1; i < n; i++)
            {
                if (matrix[i][j] == '1')
                {
                    prefixSum[i][j] = prefixSum[i - 1][j] + (matrix[i][j] - '0');
                }
                else
                {
                    prefixSum[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            vector<int> nse = nextSmallerElement(prefixSum[i]);
            vector<int> pse = previousSmallerElement(prefixSum[i]);

            for (int j = 0; j < m; j++)
            {
                mx = max(mx,prefixSum[i][j] * (nse[j] - pse[j] - 1));
            }
        }

        return mx;
    }
};

int main()
{
    Solution sol;

    // Example usage
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};

    cout << sol.maximalRectangle(matrix) << endl;

    return 0;
}
