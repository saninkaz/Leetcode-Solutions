#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int start = 0;
        int end = s.size() - 1;

        while (start <= end)
        {
            if (start <= end)
            {
                while (start <= end && !isalnum(s[start]))
                {
                    start++;
                }
            }
            if (end >= start)
            {
                while (end >= start && !isalnum(s[end]))
                {
                    end--;
                }
            }

            if (start >= end)
            {
                return true;
            }
            if (tolower(s[start]) != tolower(s[end]))
            {
                return false;
            }

            start++;
            end--;
        }
        return true;
    }
};

int main()
{
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    Solution sol;
    bool result = sol.isPalindrome(input);
    cout << "Is palindrome: " << (result ? "true" : "false") << endl;

    return 0;
}
