class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxLen = 1, curLen = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                curLen++;
                maxLen = max(maxLen, curLen);
            } else {
                curLen = 1;
            }
        }
        return maxLen;
    }
};