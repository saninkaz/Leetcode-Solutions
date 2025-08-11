class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        int count =0;
        string ans = "";

        int i = 0,j=0;
        while(i<n){
            if(s[i]=='('){
                count++;
            }
            else{
                count--;
            }

            if(count == 0){
               ans += s.substr(j+1,i-j-1);
               j=i+1;
            }

            i++;
        }

        return ans;
    }
};