#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord,
                     string endWord,
                     vector<string>& wordList) {

        unordered_set<string> words(wordList.begin(), wordList.end());

        if (!words.count(endWord)) {
            return 0;
        }

        queue<string> q;
        q.push(beginWord);

        int steps = 1;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                string current = q.front();
                q.pop();

                if (current == endWord) {
                    return steps;
                }

                // Change each character
                for (int j = 0; j < current.size(); j++) {
                    char original = current[j];

                    for (char c = 'a'; c <= 'z'; c++) {
                        current[j] = c;

                        if (words.count(current)) {
                            q.push(current);
                            words.erase(current);
                        }
                    }

                    current[j] = original;
                }
            }

            steps++;
        }

        return 0;
    }
};