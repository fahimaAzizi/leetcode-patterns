/*
------------------------------------------------
Problem: Longest Substring Without Repeating Characters
LeetCode: #3
Pattern: Sliding Window + Hash Set
Difficulty: Medium

Description:
Given a string s, find the length of the longest substring
without repeating characters.

Example:
Input: s = "abcabcbb"
Output: 3

Explanation:
The longest substring without repeating characters is "abc".

Time Complexity: O(n)
Space Complexity: O(n)

Author: Fahima Azizi
------------------------------------------------
*/

#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> seen;

        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {

            while (seen.count(s[right])) {
                seen.erase(s[left]);
                left++;
            }

            seen.insert(s[right]);

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};