class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();

        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> hash;
        for(int i=0;i<n;i++){
            hash[s[i]]++;
        }

        for(auto &it: hash){
            pq.push({it.second,it.first});
        }

        string ans = "";
        while(!pq.empty()){
            char ch = pq.top().second;
            int length = pq.top().first;
            pq.pop();
            ans += string(length, ch);
        }

        return ans;
    }
};