#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        vector<string> temp = {};

        int n = s.length();
        rec(0, s, n, temp, result);

        return result;
    }

private:
    void rec(int i, string s, int n, vector<string> &temp, vector<vector<string>> &result)
    {
        if (i >= n)
        {
            result.push_back(temp);
            return;
        }

        for (int j = i; j < n; j++)
        {
            if (isPalindrome(s, i, j))
            {
                temp.push_back(s.substr(i, (j - i) + 1));
                rec(j + 1, s, n, temp, result);
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(const string &s, int left, int right)
    {
        while (left <= right)
        {
            if (s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};

int main()
{
    Solution sol;

    // Example input
    string s = "aabb";
    vector<vector<string>> result = sol.partition(s);

    // Print the result
    for (const auto &partition : result)
    {
        cout << "[";
        for (const string &str : partition)
        {
            cout << "\"" << str << "\" ";
        }
        cout << "]" << endl;
    }

    return 0;
}
