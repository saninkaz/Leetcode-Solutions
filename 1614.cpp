class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int count =0;
        int mx = 0;

        for(int i = 0;i < n;i++){
            if(s[i]=='('){
                count++;
                mx= max(mx,count);
            }
            else if(s[i]==')'){
                count--;
            }
        }

        return mx;
    }
};