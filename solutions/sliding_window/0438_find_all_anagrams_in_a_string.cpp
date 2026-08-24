/*
------------------------------------------------
Problem: Find All Anagrams in a String
LeetCode: #438
Pattern: Sliding Window + Frequency Counting
Difficulty: Medium

Description:
Given two strings s and p, return an array of all the
start indices of p's anagrams in s.

Example:
Input:
s = "cbaebabacd"
p = "abc"

Output:
[0,6]

Explanation:
"cba" is an anagram of "abc" starting at index 0.
"bac" is an anagram of "abc" starting at index 6.

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
    vector<int> findAnagrams(string s, string p) {

        vector<int> result;

        if (p.length() > s.length()) {
            return result;
        }

        vector<int> need(26, 0);
        vector<int> window(26, 0);

        // Count characters in p.
        for (char c : p) {
            need[c - 'a']++;
        }

        int k = p.length();

        // Create the first window.
        for (int i = 0; i < k; i++) {
            window[s[i] - 'a']++;
        }

        if (window == need) {
            result.push_back(0);
        }

        // Slide the window.
        for (int right = k; right < s.length(); right++) {

            // Add new character.
            window[s[right] - 'a']++;

            // Remove character leaving the window.
            window[s[right - k] - 'a']--;

            if (window == need) {
                result.push_back(right - k + 1);
            }
        }

        return result;
    }
};