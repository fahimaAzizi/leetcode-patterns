/*
------------------------------------------------
Problem: Longest Repeating Character Replacement
LeetCode: #424
Pattern: Sliding Window + Frequency Counting
Difficulty: Medium

Description:
You are given a string s and an integer k.

You can choose any character and change it to another
uppercase English character at most k times.

Return the length of the longest substring containing
the same letter after at most k replacements.

Example:
Input: s = "AABABBA", k = 1
Output: 4

Explanation:
Replace the 'B' in "AABA" to get "AAAA".

Time Complexity: O(n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {

        vector<int> frequency(26, 0);

        int left = 0;
        int maxFrequency = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {

            int index = s[right] - 'A';

            frequency[index]++;

            maxFrequency = max(maxFrequency, frequency[index]);

            // Characters that need to be replaced.
            int replacements =
                (right - left + 1) - maxFrequency;

            // If too many replacements are needed,
            // shrink the window.
            if (replacements > k) {
                frequency[s[left] - 'A']--;
                left++;
            }

            maxLength = max(
                maxLength,
                right - left + 1
            );
        }

        return maxLength;
    }
};