/*
------------------------------------------------
Problem: Valid Anagram
LeetCode: #242
Pattern: Hashing + Frequency Counting
Difficulty: Easy

Description:
Given two strings s and t, return true if t is an anagram
of s, and false otherwise.

An anagram contains the same characters with the same
frequencies, but possibly in a different order.

Example:
Input:
s = "anagram"
t = "nagaram"

Output:
true

Time Complexity: O(n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length()) {
            return false;
        }

        vector<int> count(26, 0);

        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int value : count) {
            if (value != 0) {
                return false;
            }
        }

        return true;
    }
};
