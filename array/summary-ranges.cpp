class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        if (n == 0) 
            return result;

        int start = nums[0];
        for (int i = 1; i <= n; ++i) {
            // Check if the current number breaks the consecutive sequence
            // Use long long to avoid signed overflow when subtracting
            if (i == n || ((long long)nums[i] - (long long)nums[i - 1]) != 1) {
                if (start == nums[i - 1]) {
                    result.push_back(to_string(start));
                }
                else {
                    result.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
                }
                // Start a new range if there are more elements
                if (i < n) 
                    start = nums[i];
            }
        }
        return result;
    }
};