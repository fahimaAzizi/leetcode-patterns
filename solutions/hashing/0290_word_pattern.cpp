/*
------------------------------------------------
Problem: Word Pattern
LeetCode: #290
Pattern: Hash Map + String
Difficulty: Easy

Description:
Given a pattern and a string s, find out if s follows the
same pattern.

Example:
Input:
pattern = "abba"
s = "dog cat cat dog"

Output:
true

Time Complexity: O(n)
Space Complexity: O(n)

Author: Fahima Azizi
------------------------------------------------
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {

        vector<string> words;
        string word;
        stringstream ss(s);

        while (ss >> word) {
            words.push_back(word);
        }

        if (pattern.length() != words.size()) {
            return false;
        }

        unordered_map<char, string> patternToWord;
        unordered_map<string, char> wordToPattern;

        for (int i = 0; i < pattern.length(); i++) {

            char letter = pattern[i];
            string currentWord = words[i];

            if (patternToWord.count(letter) &&
                patternToWord[letter] != currentWord) {
                return false;
            }

            if (wordToPattern.count(currentWord) &&
                wordToPattern[currentWord] != letter) {
                return false;
            }

            patternToWord[letter] = currentWord;
            wordToPattern[currentWord] = letter;
        }

        return true;
    }
};