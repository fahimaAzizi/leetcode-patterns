/*
------------------------------------------------
Problem: Minimum Window Substring
LeetCode: #76
Pattern: Sliding Window + Hash Map
Difficulty: Hard

Description:
Given two strings s and t, return the minimum window
substring of s such that every character in t is included
in the window.

Example:
Input:
s = "ADOBECODEBANC"
t = "ABC"

Output:
"BANC"

Time Complexity: O(n)
Space Complexity: O(n)

Author: Fahima Azizi
------------------------------------------------
*/

#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> need;

        // Count characters needed from t.
        for (char c : t) {
            need[c]++;
        }

        int required = need.size();
        int formed = 0;

        unordered_map<char, int> window;

        int left = 0;

        int minLength = INT_MAX;
        int minStart = 0;

        for (int right = 0; right < s.length(); right++) {

            char c = s[right];

            window[c]++;

            // Check if this character requirement is satisfied.
            if (need.count(c) &&
                window[c] == need[c]) {

                formed++;
            }

            // Try to shrink the window.
            while (left <= right && formed == required) {

                // Update the smallest window.
                if (right - left + 1 < minLength) {

                    minLength = right - left + 1;
                    minStart = left;
                }

                char leftChar = s[left];

                window[leftChar]--;

                // Window is no longer valid.
                if (need.count(leftChar) &&
                    window[leftChar] < need[leftChar]) {

                    formed--;
                }

                left++;
            }
        }

        if (minLength == INT_MAX) {
            return "";
        }

        return s.substr(minStart, minLength);
    }
};