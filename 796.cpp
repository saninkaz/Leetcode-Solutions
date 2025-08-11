class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.length();
        
        if(n!=m) return false;
        int i =0;
        int j =0;

       string str = s+s;
       for(int i =0;i<=n;i++){
        if(str.substr(i,n)==goal){
            return true;
        }
       }

       return false;
    }
};