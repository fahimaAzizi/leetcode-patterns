/*
------------------------------------------------
Problem: First Unique Character in a String
LeetCode: #387
Pattern: Hashing + Frequency Counting
Difficulty: Easy

Description:
Given a string s, find the first non-repeating character
and return its index.

If it does not exist, return -1.

Example:
Input: s = "leetcode"
Output: 0

Explanation:
'l' appears only once and is the first unique character.

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
    int firstUniqChar(string s) {

        vector<int> frequency(26, 0);

        // Count each character.
        for (char c : s) {
            frequency[c - 'a']++;
        }

        // Find the first character that appears once.
        for (int i = 0; i < s.length(); i++) {
            if (frequency[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};