class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numbers(nums.begin(), nums.end());

        int longest = 0;

        for (int num : numbers) {
            // Check if this is the beginning of a sequence
            if (numbers.find(num - 1) == numbers.end()) {
                int current = num;
                int length = 1;

                while (numbers.find(current + 1) != numbers.end()) {
                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};