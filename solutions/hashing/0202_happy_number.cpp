/*
------------------------------------------------
Problem: Happy Number
LeetCode: #202
Pattern: Hash Set + Cycle Detection
Difficulty: Easy

Description:
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by repeatedly replacing
the number by the sum of the squares of its digits.

If the process reaches 1, the number is happy.

If the process enters a cycle that does not include 1,
the number is not happy.

Example:
Input: n = 19
Output: true

Explanation:
1² + 9² = 82
8² + 2² = 68
6² + 8² = 100
1² + 0² + 0² = 1

Time Complexity: O(log n)
Space Complexity: O(log n)

Author: Fahima Azizi
------------------------------------------------
*/

#include <unordered_set>

using namespace std;

class Solution {
public:

    int getNext(int n) {

        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {

        unordered_set<int> seen;

        while (n != 1 && !seen.count(n)) {

            seen.insert(n);

            n = getNext(n);
        }

        return n == 1;
    }
};