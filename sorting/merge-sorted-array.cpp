class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int end_1 = m - 1;
        int end_2 = n - 1;
        int end_merge = m + n - 1;
        while (end_1 >= 0 && end_2 >= 0) {
            if (nums1[end_1] >= nums2[end_2]) {
                nums1[end_merge] = nums1[end_1];
                end_merge--;
                end_1--;
            }
            else {
                nums1[end_merge] = nums2[end_2];
                end_merge--;
                end_2--;
            }
        }
        while (end_2 >= 0) {
                nums1[end_merge] = nums2[end_2];
                end_2--;
                end_merge--;
        }
    }
};