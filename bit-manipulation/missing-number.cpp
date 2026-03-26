class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int total = n * (n + 1) / 2;   // 完整总和
    int sum = 0;
    for (int num : nums) {
        sum += num;                // 实际总和
    }
    return total - sum;
}
};