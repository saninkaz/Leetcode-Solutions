#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

// Function to find the length of the longest substring without repeating characters

// Solution 1

// int lengthOfLongestSubstring(string s)
// {
//     int length = 0;
//     if(s.length()>0){
//         length++;
//         }
//     for (int i = 0; i < s.length(); i++)
//     {
//         string test = "";
//         test+= s[i];
//         for (int j = i+1; j < s.length(); j++)
//         {
//             if(test.find(s[j]) != string::npos){
//                 length = (length > test.length()) ? length : test.length();
//                 break;
//             }
//             test+=s[j];
//             length = (length > test.length()) ? length : test.length();

//         }
//     }

//     return length;
// }

// Solution 2

int lengthOfLongestSubstring(string s)
{
    int length = 0;
    if(s.length()>0){
        length++;
        }
    string test = "";
    test+= s[0];
    for (int i = 1; i < s.length(); i++)
    {

        int index = test.find(s[i]);
        if(index != string::npos){
            test = test.substr(index+1,(test.length()-1));
        }

        test += s[i];
        length = (length > test.length()) ? length : test.length();
    }

    return length;
}


int main()
{
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int result = lengthOfLongestSubstring(input);
    cout << "Length of the longest substring without repeating characters: " << result << endl;

    return 0;
}
