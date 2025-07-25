#include <bits/stdc++.h>
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
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        int ans = heights[0];

        vector<int> nse = nextSmallerElement(heights);
        vector<int> pse = previousSmallerElement(heights);

        for (int i = 0; i < n; i++)
        {
            ans = max((heights[i] * ((nse[i] - i) + (i - pse[i]))-heights[i]), ans);
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    
    vector<int> heights = {2, 1, 5, 6, 2, 3}; // Example input
    int result = sol.largestRectangleArea(heights);
    cout << result << endl; // Expected Output: 10 (for the example above)
    return 0;
}
