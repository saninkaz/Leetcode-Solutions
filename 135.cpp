#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        int count = 0;

        vector<int> candies(n, 1);

        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {

            if (ratings[i] > ratings[i + 1])
            {

                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
            count += candies[i];
        }

        count += candies[n - 1];
        return count;
    }
};

int main()
{
    int n;
    cout << "Enter number of children: ";
    cin >> n;

    vector<int> ratings(n);
    cout << "Enter the ratings:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> ratings[i];
    }

    Solution sol;
    int result = sol.candy(ratings);
    cout << "Minimum candies required: " << result << endl;

    return 0;
}
