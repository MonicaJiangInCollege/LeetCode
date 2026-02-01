class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();

        int uniq_count = 0;
        for (int i = 1; i < size ; i++) {
            if (nums[i] != nums[uniq_count]) {
                uniq_count++;
                nums[uniq_count] = nums[i];
            }
        }

        return uniq_count+1;
    }
};