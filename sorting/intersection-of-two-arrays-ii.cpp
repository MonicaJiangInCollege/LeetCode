#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count;
        vector<int> result;

        // 统计 nums1 中每个数字出现次数
        for (int num : nums1) {
            count[num]++;
        }

        // 遍历 nums2
        for (int num : nums2) {
            if (count[num] > 0) {
                result.push_back(num);
                count[num]--;  // 用掉一次
            }
        }

        return result;
    }
};