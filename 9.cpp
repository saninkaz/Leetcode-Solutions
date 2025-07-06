#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) {
            string str=to_string(x);
            int i=0;
            int j=str.size()-1;
            while(i<=j){
                if(str[i]!=str[j]){
                    return false;
                }
                i++;
                j--;
            }
            return true;
        }
    };

int main() {
    Solution sol;
    int x;
    cout << "Enter an integer: ";
    cin >> x;

    bool result = sol.isPalindrome(x);
    cout << "Is palindrome: " << (result ? "true" : "false") << endl;

    return 0;
}
