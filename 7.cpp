#include <iostream>
#include <climits>  // for INT_MAX and INT_MIN
using namespace std;
#include<bits/stdc++.h>


class Solution {
    public:
        int reverse(int x) {
            int ans=0;
            int d;
            while(x>0 || x<0){
                d=x%10;
                if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && d > 7)) return 0;
                if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && d < -8)) return 0;
                ans = (ans*10)+d;
                x=x/10;
            }
            return ans;
        }
    };


int main() {
    Solution sol;
    int x;
    cout << "Enter an integer: ";
    cin >> x;

    int reversed = sol.reverse(x);
    cout << "Reversed integer: " << reversed << endl;

    return 0;
}