/*
------------------------------------------------
Problem: Isomorphic Strings
LeetCode: #205
Pattern: Hash Map + String
Difficulty: Easy

Description:
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be
replaced to get t, with the same character always mapping
to the same character.

Example:
Input:
s = "egg"
t = "add"

Output:
true

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
    bool isIsomorphic(string s, string t) {

        vector<int> mapS(256, -1);
        vector<int> mapT(256, -1);

        for (int i = 0; i < s.length(); i++) {

            char a = s[i];
            char b = t[i];

            if (mapS[a] != -1 && mapS[a] != b) {
                return false;
            }

            if (mapT[b] != -1 && mapT[b] != a) {
                return false;
            }

            mapS[a] = b;
            mapT[b] = a;
        }

        return true;
    }
};