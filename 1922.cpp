#include <iostream>
using namespace std;

// Time limit exceeded

// class Solution
// {
// public:
//     int countGoodNumbers(long long n)
//     {
//         const int MOD = 1e9 + 7;
//         long long result = 1;

//         for (int i = 0; i < n; i++)
//         {
//             if (i % 2 == 0)
//             {
//                 result = (result * 5) % MOD;
//             }
//             else
//             {
//                 result = (result * 4) % MOD;
//             }
//         }
//         return result;
//     }
// };

// Optimal solution

class Solution
{
    const int MOD = 1e9 + 7;

private:
    long long pow(int x, long long n)
    {
        if (n == 1)
            return x % MOD;
        if (n == 0)
            return 1;

        long long y = pow(x, n / 2) % MOD;
        long long res = (y * y) % MOD;

        if (n % 2 == 0)
        {
            return res;
        }
        else
        {
            return (x * res) % MOD;
        }
    }

public:
    int countGoodNumbers(long long n)
    {
        const int MOD = 1e9 + 7;
        long long result = 1;

        if (n % 2 == 0)
        {
            int x = 20;
            result = pow(x, n / 2);
        }

        else
        {
            int x = 20;
            result = pow(x, (n - 1) / 2);
            result= (result*5) % MOD;
        }

        return result;
    }
};

int main()
{
    Solution sol;

    // Example test cases
    cout << sol.countGoodNumbers(1) << endl;  // Expected: 5
    cout << sol.countGoodNumbers(15) << endl;  // Expected: 400
    cout << sol.countGoodNumbers(50) << endl; // Expected: 564908303

    return 0;
}
