/*
------------------------------------------------
Problem: Is Subsequence
LeetCode: #392
Pattern: Two Pointers
Difficulty: Easy

Description:
Given two strings s and t, return true if s is a
subsequence of t.

A subsequence keeps the same order, but characters do not
need to be next to each other.

Example:
Input:
s = "abc"
t = "ahbgdc"

Output:
true

Time Complexity: O(n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {

        int i = 0;
        int j = 0;

        while (i < s.length() && j < t.length()) {

            if (s[i] == t[j]) {
                i++;
            }

            j++;
        }

        return i == s.length();
    }
};