// Last updated: 10/12/2026, 9:55:35 PM
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> remaining(wordList.begin(), wordList.end());
        remaining.erase(beginWord);
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (!q.empty()) {
            auto [word, length] = q.front();
            q.pop();
            if (word == endWord) return length;
            for (int i = 0; i < (int)word.size(); ++i) {
                string candidate = word;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    candidate[i] = ch;
                    if (remaining.erase(candidate))
                        q.push({candidate, length + 1});
                }
            }
        }
        return 0;
    }
};