/*
------------------------------------------------
Problem: Permutation in String
LeetCode: #567
Pattern: Sliding Window + Frequency Counting
Difficulty: Medium

Description:
Given two strings s1 and s2, return true if s2 contains
a permutation of s1.

Example:
Input:
s1 = "ab"
s2 = "eidbaooo"

Output:
true

Explanation:
"ba" is a permutation of "ab" and appears in s2.

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
    bool checkInclusion(string s1, string s2) {

        if (s1.length() > s2.length()) {
            return false;
        }

        vector<int> need(26, 0);
        vector<int> window(26, 0);

        // Count characters needed from s1.
        for (char c : s1) {
            need[c - 'a']++;
        }

        int k = s1.length();

        // Build the first window.
        for (int i = 0; i < k; i++) {
            window[s2[i] - 'a']++;
        }

        if (window == need) {
            return true;
        }

        // Slide the window.
        for (int i = k; i < s2.length(); i++) {

            // Add new character.
            window[s2[i] - 'a']++;

            // Remove character leaving the window.
            window[s2[i - k] - 'a']--;

            if (window == need) {
                return true;
            }
        }

        return false;
    }
};