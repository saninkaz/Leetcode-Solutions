class Solution {
public:
    int romanToInt(string s) {
        
        int n = s.length();
        int ans =0;
        int i=0;

        while(i<n){
            if(s[i]=='I'){
                if(i < n && s[i+1]=='V'){
                    ans = (ans)+4;
                    i+=2;
                }
                else if(i < n && s[i+1]=='X'){
                    ans = (ans)+9;
                    i+=2;
                }
                else{
                    ans= (ans)+1;
                    i++;
                }
            }
            if(s[i]=='X'){
                if(i < n && s[i+1]=='L'){
                    ans = (ans)+40;
                    i+=2;
                }
                else if(i < n && s[i+1]=='C'){
                    ans = (ans)+90;
                    i+=2;
                }
                else{
                    ans= (ans)+10;
                    i++;
                }
            }
            if(s[i]=='C'){
                if(i < n && s[i+1]=='D'){
                    ans = (ans)+400;
                    i+=2;
                }
                else if(i < n && s[i+1]=='M'){
                    ans = (ans)+900;
                    i+=2;
                }
                else{
                    ans= (ans)+100;
                    i++;
                }
            }
            if(s[i]=='V'){
                ans= (ans)+5;
                i++;
            }
            if(s[i]=='L'){
                ans= (ans)+50;
                i++;
            }
            if(s[i]=='D'){
                ans= (ans)+500;
                i++;
            }
            if(s[i]=='M'){
                ans= (ans)+1000;
                i++;
            }
        }

        return ans;
    }
};