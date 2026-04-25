class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // 计算第一个窗口的和
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        int maxSum = sum;
        // 滑动窗口
        for (int i = k; i < nums.size(); ++i) {
            sum += nums[i] - nums[i - k];
            if (sum > maxSum) maxSum = sum;
        }
        return static_cast<double>(maxSum) / k;
    }
};