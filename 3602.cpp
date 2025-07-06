class Solution {
public:
    string concatHex36(int n) {
        int n2= n*n;
        int n3 = n2*n;

        string hexd = "";
        string hexg = "";

        while(n2>0){
            int r = n2%16;
            n2 = n2/16;

            if(r<=9 && r>=0){
                hexd+= to_string(r);
            }
            else{
                char ad = 'A'+ (r-10);
                hexd+= ad;
            }
            
        }

        reverse(hexd.begin(),hexd.end());

        while(n3>0){
            int r = n3%36;
            n3 = n3/36;

            if(r<=9 && r>=0){
                hexg+= to_string(r);
            }
            else{
                char ad = 'A'+ (r-10);
                hexg+= ad;
            }
            
        }

        reverse(hexg.begin(),hexg.end());

        return (hexd+hexg);

        
    }
};