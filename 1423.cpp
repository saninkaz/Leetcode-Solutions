#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {

        int n = cardPoints.size();

        int i = 0;
        int j = n - 1;
        int mx = 0;
        int lsum = 0;
        int rsum = 0;

        for (int i = 0; i < k; i++)
        {
            lsum += cardPoints[i];
            mx = max(mx, lsum);
        }

        for (int i = 0; i < k; i++)
        {
            lsum -= cardPoints[k-i-1];
            rsum += cardPoints[n-1-i];
            mx = max(lsum + rsum, mx);
        }

        return mx;
    }
};

int main()
{
    Solution sol;
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    int result = sol.maxScore(cardPoints, k);
    cout << "Maximum score: " << result << endl;
    return 0;
}
