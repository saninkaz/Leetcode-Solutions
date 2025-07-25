#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i] =='[' || s[i]=='{'){
                st.push(s[i]);
            }
            if(s[i]==')'){
                if(st.size() && st.top()=='('){
                    st.pop();
                }
                else{
                    return false; 
                }
            }
            else if(s[i]==']'){
                if(st.size() && st.top()=='['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i]=='}'){
                if(st.size() && st.top()=='{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        
        return !st.size();
    }
};

int main() {
    Solution sol;

    vector<string> testCases = {
        "()",         // true
        "()[]{}",     // true
        "(]",         // false
        "([])",       // true
        "([)]"        // false
    };

    for (const string& s : testCases) {
        bool result = sol.isValid(s);
        cout << "Input: " << s << " -> Output: " << (result ? "true" : "false") << endl;
    }

    return 0;
}
