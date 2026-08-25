/*
------------------------------------------------
Problem: Backspace String Compare
LeetCode: #844
Pattern: Two Pointers
Difficulty: Easy

Description:
Given two strings s and t, return true if they are equal
when both are typed into empty text editors.

The character '#' means a backspace.

Example:
Input:
s = "ab#c"
t = "ad#c"

Output:
true

Explanation:
"ab#c" becomes "ac"
"ad#c" becomes "ac"

Time Complexity: O(n + m)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

#include <string>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {

        int i = s.length() - 1;
        int j = t.length() - 1;

        int skipS = 0;
        int skipT = 0;

        while (i >= 0 || j >= 0) {

            // Find the next valid character in s.
            while (i >= 0) {

                if (s[i] == '#') {
                    skipS++;
                    i--;
                }

                else if (skipS > 0) {
                    skipS--;
                    i--;
                }

                else {
                    break;
                }
            }

            // Find the next valid character in t.
            while (j >= 0) {

                if (t[j] == '#') {
                    skipT++;
                    j--;
                }

                else if (skipT > 0) {
                    skipT--;
                    j--;
                }

                else {
                    break;
                }
            }

            // Compare characters.
            if (i >= 0 && j >= 0) {

                if (s[i] != t[j]) {
                    return false;
                }
            }

            // One string has characters left but the other doesn't.
            else if (i >= 0 || j >= 0) {
                return false;
            }

            i--;
            j--;
        }

        return true;
    }
};