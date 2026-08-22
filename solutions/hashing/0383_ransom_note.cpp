/*
------------------------------------------------
Problem: Ransom Note
LeetCode: #383
Pattern: Hashing + Frequency Counting
Difficulty: Easy

Description:
Given two strings ransomNote and magazine, return true if
ransomNote can be constructed by using the letters from
magazine.

Each letter in magazine can only be used once.

Example:
Input:
ransomNote = "a"
magazine = "b"

Output:
false

Example:
Input:
ransomNote = "aa"
magazine = "aab"

Output:
true

Time Complexity: O(n + m)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        vector<int> frequency(26, 0);

        // Count the letters available in magazine.
        for (char c : magazine) {
            frequency[c - 'a']++;
        }

        // Use letters to build ransomNote.
        for (char c : ransomNote) {

            frequency[c - 'a']--;

            if (frequency[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};