class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;

        for (int num : nums) {
            frequency[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);

        for (auto& pair : frequency) {
            buckets[pair.second].push_back(pair.first);
        }

        vector<int> answer;

        for (int freq = buckets.size() - 1; freq >= 0; freq--) {
            for (int num : buckets[freq]) {
                answer.push_back(num);

                if (answer.size() == k) {
                    return answer;
                }
            }
        }

        return answer;
    }
};