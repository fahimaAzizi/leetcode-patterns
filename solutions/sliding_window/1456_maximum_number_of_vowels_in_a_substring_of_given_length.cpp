/*
------------------------------------------------
Problem: Maximum Number of Vowels in a Substring of Given Length
LeetCode: #1456
Pattern: Sliding Window
Difficulty: Medium

Description:
Given a string s and an integer k, return the maximum number
of vowel letters in any substring of s with length k.

Example:
Input: s = "abciiidef", k = 3
Output: 3

Explanation:
The substring "iii" contains 3 vowels.

Time Complexity: O(n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' ||
               c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {

        int currentVowels = 0;

        // Count vowels in the first window.
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                currentVowels++;
            }
        }

        int maxVowels = currentVowels;

        // Slide the window.
        for (int i = k; i < s.length(); i++) {

            // Add the new character.
            if (isVowel(s[i])) {
                currentVowels++;
            }

            // Remove the character leaving the window.
            if (isVowel(s[i - k])) {
                currentVowels--;
            }

            maxVowels = max(maxVowels, currentVowels);
        }

        return maxVowels;
    }
};