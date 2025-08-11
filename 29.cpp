#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == divisor)
            return 1;

        bool sign = true;
        if (dividend >= 0 && divisor < 0)
            sign = false;
        if (dividend < 0 && divisor > 0)
            sign = false;

        long n = abs(dividend);
        long d = abs(divisor);

        int ans = 0;

        while (n >= d)
        {
            int count = 0;
            while (n >= (d << count + 1))
            {
                count++;
            }

            ans += 1 << count;
            n -= d * (1 << count);
        }

        if (ans > 2e31 - 1 && sign == true)
        {
            return INT_MAX;
        }

        if (ans > 2e31 && sign == false)
        {
            return INT_MIN;
        }

        ans = sign ? ans : -ans;

        return ans;
    }
};

int main()
{
    Solution sol;
    int dividend = 10; // Example input
    int divisor = 3;   // Example input

    cout << sol.divide(dividend, divisor) << endl;

    return 0;
}
