class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n = nums.size();
        // 期望的和与平方和
        long long expected_sum = n * (n + 1) / 2;
        long long expected_sq_sum = n * (n + 1) * (2 * n + 1) / 6;
        
        long long actual_sum = 0, actual_sq_sum = 0;
        for (int num : nums) {
            actual_sum += num;
            actual_sq_sum += (long long)num * num;
        }
        
        long long diff_sum = actual_sum - expected_sum;        // dup - missing
        long long diff_sq_sum = actual_sq_sum - expected_sq_sum; // dup^2 - missing^2
        
        long long sum_md = diff_sq_sum / diff_sum;              // dup + missing
        
        int dup = (diff_sum + sum_md) / 2;
        int missing = sum_md - dup;
        
        return {dup, missing};
    }
};