class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int length = nums.size();
        int begin = 0;
        int end = length - 1;
        int mid = begin + (end - begin) / 2; // 防止溢出
        while (begin<=end) {
            if (nums[mid] < target) {
                begin = mid + 1;
                mid = begin + (end - begin) / 2;
            }
            else if (nums[mid] > target) {
                end = mid - 1;
                mid = begin + (end - begin) / 2;
            }
            else {
                return mid;
            }
        }
        return begin;
    }
};