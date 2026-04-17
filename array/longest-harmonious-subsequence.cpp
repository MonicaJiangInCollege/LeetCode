class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        int longest = 0;
        for (auto& [num, cnt] : freq) {
            if (freq.count(num + 1)) {
                longest = max(longest, cnt + freq[num + 1]);
            }
        }
        return longest;
    }
};