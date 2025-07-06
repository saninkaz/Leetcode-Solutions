class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<int,string>> resultd;
        unordered_map<string, int> priority = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };
        int n = code.size();

        for(int i=0;i<n;i++){
            int found =0;
            if(!code[i].empty() && isActive[i] == true && (businessLine[i] == "electronics" || businessLine[i] == "grocery" || businessLine[i] == "pharmacy" || businessLine[i] == "restaurant")){
            for(int j=0;j<code[i].size();j++){
            if(!isalnum(code[i][j]) && code[i][j]!= '_'){
                found =1;
                break;
            }
                }
            if(!found) resultd.push_back({priority[businessLine[i]],code[i]});
            }
        }

        sort(resultd.begin(),resultd.end());

        vector<string> result;
        for (auto& [_, c] : resultd) {
            result.push_back(c);
        }
         return result;
    }
};