class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastIndex; // 记录每个数字最近出现的下标
        for (int i = 0; i < nums.size(); ++i) {
            // 如果当前数字已经出现过，且下标差 ≤ k，则找到答案
            if (lastIndex.count(nums[i]) && i - lastIndex[nums[i]] <= k) {
                return true;
            }
            // 更新当前数字的最新下标
            lastIndex[nums[i]] = i;
        }
        return false;
    }
};