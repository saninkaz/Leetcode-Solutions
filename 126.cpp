#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// Solution1 (does not wokr in leetcode) (works for interview)

class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<vector<string>> result;

        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});

        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);

        int level = 0;

        if (st.find(endWord) == st.end()) return result;

        while (!q.empty())
        {
            vector<string> vec = q.front();
            q.pop();

            if (vec.size() > level)
            {
                level++;
                for (auto it : usedOnLevel)
                {
                    st.erase(it);
                }
                usedOnLevel.clear();
            }

            string word = vec.back();

            if (word == endWord)
            {
                int depth = vec.size();
                result.push_back(vec);
                while (!q.empty())
                {
                    vector<string> vec2 = q.front();
                    q.pop();

                    string word2 = vec2.back();
                    if (vec2.size() == depth)
                    {
                        if (word2 == endWord)
                        {
                            result.push_back(vec2);
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                return result;
            }
            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.find(word) != st.end())
                    {
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }

        return result;
    }
};

// Solution 2 (works for leetcode)

// class Solution
// {
//     unordered_map<string, int> mpp;
//     vector<vector<string>> result;
//     string b;

// private:
//     void dfs(string word, vector<string> &seq)
//     {
//         if (word == b)
//         {
//             result.push_back(seq);
//             return;
//         }
//         else
//         {
//             int depth = mpp[word];
//             int sz = word.size();
//             for (int i = 0; i < sz; i++)
//             {
//                 char original = word[i];
//                 for (char ch = 'a'; ch <= 'z'; ch++)
//                 {
//                     word[i] = ch;
//                     if (mpp.find(word) != mpp.end())
//                     {
//                         if (mpp[word] == depth - 1)
//                         {
//                             seq.push_back(word);
//                             dfs(word, seq);
//                             seq.pop_back();
//                         }
//                     }
//                 }
//                 word[i] = original;
//             }
//         }
//     }

// public:
//     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
//     {

//         unordered_set<string> st(wordList.begin(), wordList.end());
//         st.erase(beginWord);
//         b = beginWord;
//         queue<string> q;
//         q.push(beginWord);

//         mpp[beginWord] = 1;

//         while (!q.empty())
//         {
//             string word = q.front();
//             int sz = word.size();
//             int depth = mpp[word];
//             q.pop();
//             if(word==endWord) break;
//             for (int i = 0; i < sz; i++)
//             {
//                 char original = word[i];
//                 for (char ch = 'a'; ch <= 'z'; ch++)
//                 {
//                     word[i] = ch;
//                     if (st.find(word) != st.end())
//                     {
//                         q.push({word});
//                         mpp[word] = depth + 1;
//                         st.erase(word);
//                     }
//                 }
//                 word[i] = original;
//             }
//         }

//         if (mpp.find(endWord) != mpp.end())
//         {
//             vector<string> seq;
//             seq.push_back(endWord);
//             dfs(endWord, seq);
//         }

//         for(auto &words: result){
//             reverse(words.begin(), words.end());
//         }
        
//         return result;
//     }
// };

int main()
{
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    vector<vector<string>> result = sol.findLadders(beginWord, endWord, wordList);

    for (auto &seq : result)
    {
        for (auto &word : seq)
        {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
