/*
------------------------------------------------
Problem: Group Anagrams
LeetCode: #49
Pattern: Hashing + Sorting
Difficulty: Medium

Description:
Given an array of strings strs, group the anagrams together.

Example:
Input:
strs = ["eat","tea","tan","ate","nat","bat"]

Output:
[
    ["bat"],
    ["nat","tan"],
    ["ate","eat","tea"]
]

Time Complexity: O(n * k log k)
Space Complexity: O(n * k)

Author: Fahima Azizi
------------------------------------------------
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> groups;

        for (string word : strs) {

            string key = word;

            sort(key.begin(), key.end());

            groups[key].push_back(word);
        }

        vector<vector<string>> result;

        for (auto& group : groups) {
            result.push_back(group.second);
        }

        return result;
    }
};