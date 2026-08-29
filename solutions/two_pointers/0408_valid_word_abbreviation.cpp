/*
------------------------------------------------
Problem: Valid Word Abbreviation
LeetCode: #408
Pattern: Two Pointers + String Parsing
Difficulty: Easy

Description:
Given a word and an abbreviation, return true if the
abbreviation correctly represents the word.

Numbers in the abbreviation represent how many characters
are skipped.

Example:
word = "internationalization"
abbr = "i12iz4n"

Output:
true

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
    bool validWordAbbreviation(string word, string abbr) {

        int i = 0;
        int j = 0;

        while (i < word.length() && j < abbr.length()) {

            // If characters are the same, move both pointers.
            if (isalpha(abbr[j])) {

                if (word[i] != abbr[j]) {
                    return false;
                }

                i++;
                j++;
            }

            else {

                // Abbreviation cannot start a number with 0.
                if (abbr[j] == '0') {
                    return false;
                }

                int number = 0;

                // Read the complete number.
                while (j < abbr.length() && isdigit(abbr[j])) {
                    number = number * 10 + (abbr[j] - '0');
                    j++;
                }

                // Skip characters in the word.
                i += number;
            }
        }

        return i == word.length() && j == abbr.length();
    }
};