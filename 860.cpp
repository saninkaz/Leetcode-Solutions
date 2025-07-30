#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int n = bills.size();

        int five = 0, ten = 0;

        for (int i = 0; i < n; i++)
        {
            if (bills[i] == 5)
            {
                five++;
            }
            else if (bills[i] == 10)
            {
                if (five <= 0)
                {
                    return false;
                }
                ten++;
                five--;
            }

            else
            {
                if (ten > 0 && five > 0)
                {
                    ten--;
                    five--;
                    continue;
                }
                else if (five > 2)
                {
                    five -= 3;
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> bills = {5, 5, 5, 10, 20}; // Sample input
    bool result = sol.lemonadeChange(bills);
    cout << (result ? "true" : "false") << endl;
    return 0;
}
