#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPossibleOriginals(string word)
    {

        int n = word.length();
        int sum = 1;

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && word[i] == word[i - 1])
            {
                sum++;
            }
        }
        return sum;
    }
};

int main()
{
    string word;
    cin >> word;

    Solution sol;
    int result = sol.countPossibleOriginals(word);

    cout << result << endl;

    return 0;
}
