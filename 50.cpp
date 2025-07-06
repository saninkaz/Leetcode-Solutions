#include <iostream>
using namespace std;

class Solution
{
public:
    double myPow(double x, long long n)
    {
        if(n==0) return 1;

        if (n < 0) {
            return 1.0 / myPow(x, -(long long)n);
        }

        if(n % 2 ==0){
            double y = myPow(x,n/2);
            return y*y;
        }
        else{
            return x*myPow(x,n-1);
        }
    }
};

int main()
{
    Solution sol;

    // Test cases
    double x1 = 2.00000;
    int n1 = 10;
    double x2 = 2.10000;
    int n2 = 3;
    double x3 = 2.00000;
    int n3 = -2;

    cout << fixed;
    cout.precision(5);

    cout << "myPow(" << x1 << ", " << n1 << ") = " << sol.myPow(x1, n1) << endl;
    cout << "myPow(" << x2 << ", " << n2 << ") = " << sol.myPow(x2, n2) << endl;
    cout << "myPow(" << x3 << ", " << n3 << ") = " << sol.myPow(x3, n3) << endl;

    return 0;
}
