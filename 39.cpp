#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    void rec(int i, vector<int> &candidates, vector<int> &temp, vector<vector<int>> &result, int n, int sum, int target)
    {
        if (sum == target)
        {
            result.push_back(temp);
            return;
        }
        if (sum > target)
        {
            return;
        }

        if (i >= n)
        {
            return;
        }

        temp.push_back(candidates[i]);
        sum += candidates[i];
        rec(i, candidates, temp, result, n, sum, target);
        temp.pop_back();
        sum -= candidates[i];
        rec(i + 1, candidates, temp, result, n, sum, target);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;

        int i = 0;
        int sum = 0;
        int n = candidates.size();
        vector<int> temp = {};

        rec(i, candidates, temp, result, n, sum, target);

        return result;
    }
};

int main()
{
    Solution sol;

    // Example input
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = sol.combinationSum(candidates, target);

    // Print the result
    for (const auto &combination : result)
    {
        cout << "[";
        for (int num : combination)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
