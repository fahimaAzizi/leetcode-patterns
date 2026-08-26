/*
------------------------------------------------
Problem: Valid Palindrome
LeetCode: #125
Pattern: Two Pointers + String
Difficulty: Easy

Description:
Given a string s, return true if it is a palindrome,
or false otherwise.

A palindrome reads the same forward and backward.

Ignore:
- Uppercase/lowercase differences
- Non-alphanumeric characters

Example:
Input: s = "A man, a plan, a canal: Panama"
Output: true

Time Complexity: O(n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {

            // Skip non-alphanumeric characters from the left.
            while (left < right && !isalnum(s[left])) {
                left++;
            }

            // Skip non-alphanumeric characters from the right.
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // Compare characters ignoring uppercase/lowercase.
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};