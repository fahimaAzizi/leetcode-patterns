/*
------------------------------------------------
Problem: Reverse Vowels of a String
LeetCode: #345
Pattern: Two Pointers
Difficulty: Easy

Description:
Given a string s, reverse only the vowels in the string.

Example:
Input: s = "hello"
Output: "holle"

Time Complexity: O(n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

#include <string>

using namespace std;

class Solution {
public:

    bool isVowel(char c) {
        return c == 'a' || c == 'e' ||
               c == 'i' || c == 'o' ||
               c == 'u' || c == 'A' ||
               c == 'E' || c == 'I' ||
               c == 'O' || c == 'U';
    }

    string reverseVowels(string s) {

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {

            // Move left until we find a vowel.
            while (left < right && !isVowel(s[left])) {
                left++;
            }

            // Move right until we find a vowel.
            while (left < right && !isVowel(s[right])) {
                right--;
            }

            // Swap the vowels.
            swap(s[left], s[right]);

            left++;
            right--;
        }

        return s;
    }
};