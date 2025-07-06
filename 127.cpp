#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {

        queue<pair<string, int>> q;

        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        if(st.find(endWord) == st.end()){
            return 0;
        }

        while (!q.empty())
        {
            string word = q.front().first;
            int depth = q.front().second;
            q.pop();

            if(word == endWord){
                return depth;
            }

            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.find(word) != st.end())
                    {
                        q.push({word,depth+1});
                        st.erase(word);
                    }
                }
                word[i]=original;
            }
        }

        return 0;
    }
};

int main()
{
    Solution sol;

    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    int result = sol.ladderLength(beginWord, endWord, wordList);

    cout << result << endl;

    return 0;
}
