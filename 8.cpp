#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0;
        int n = s.length();
        long long ans = 0;
        int neg = 0;

        while (i < n)
        {
            if (isspace(s[i]))
            {
                i++;
            }
            else
            {
                break;
            }
        }

        if (isalpha(s[i]) && s[i] != '-' && s[i] != '+')
        {
            return 0;
        }
        if (s[i] == '+')
        {
            i++;
        }
        else if (s[i] == '-')
        {
            neg = 1;
            i++;
        }

        while (i < n)
        {
            if (isdigit(s[i]))
            {
                ans = ans * 10;
                ans += s[i] - '0';
                if (!neg && ans > INT_MAX)
                {
                    return INT_MAX;
                }
                if (neg && -ans < INT_MIN)
                    return INT_MIN;
            }
            if (!isdigit(s[i]))
            {
                if (neg)
                {
                    ans *= -1;
                }
                return ans;
            }
            i++;
        }

        if (neg)
        {
            ans *= -1;
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    string input1 = "21474836460";
    string input2 = "  -0012a42";
    string input3 = "1337c0d3";
    string input4 = "0-1";
    string input5 = "words and 987";

    cout << "Input: \"" << input1 << "\" -> Output: " << sol.myAtoi(input1) << endl;
    cout << "Input: \"" << input2 << "\" -> Output: " << sol.myAtoi(input2) << endl;
    cout << "Input: \"" << input3 << "\" -> Output: " << sol.myAtoi(input3) << endl;
    cout << "Input: \"" << input4 << "\" -> Output: " << sol.myAtoi(input4) << endl;
    cout << "Input: \"" << input5 << "\" -> Output: " << sol.myAtoi(input5) << endl;

    return 0;
}
