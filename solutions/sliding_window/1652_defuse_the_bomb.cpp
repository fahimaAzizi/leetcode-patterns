/*
------------------------------------------------
Problem: Defuse the Bomb
LeetCode: #1652
Pattern: Sliding Window + Circular Array
Difficulty: Easy

Description:
You are given a circular array code and an integer k.

If k > 0, replace each number with the sum of the next k
numbers.

If k < 0, replace each number with the sum of the previous
k numbers.

If k == 0, replace every number with 0.

Example:
Input:
code = [5,7,1,4], k = 3

Output:
[12,10,16,13]

Time Complexity: O(n)
Space Complexity: O(n)

Author: Fahima Azizi
------------------------------------------------
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {

        int n = code.size();
        vector<int> result(n, 0);

        if (k == 0) {
            return result;
        }

        int windowSum = 0;

        if (k > 0) {

            // Sum the first k elements after index 0.
            for (int i = 1; i <= k; i++) {
                windowSum += code[i % n];
            }

            for (int i = 0; i < n; i++) {

                result[i] = windowSum;

                // Remove old value.
                windowSum -= code[(i + 1) % n];

                // Add new value.
                windowSum += code[(i + k + 1) % n];
            }

        } else {

            k = -k;

            // Sum the previous k elements.
            for (int i = 1; i <= k; i++) {
                windowSum += code[(n - i) % n];
            }

            for (int i = 0; i < n; i++) {

                result[i] = windowSum;

                // Remove old value.
                windowSum -= code[(i - k + n) % n];

                // Add new value.
                windowSum += code[i];
            }
        }

        return result;
    }
};