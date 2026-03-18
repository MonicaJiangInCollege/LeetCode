class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;  // 用于记录已经出现过的元素
        for (int num : nums) {  // 遍历数组中的每个数字
            if (seen.count(num)) {  // 如果当前数字已经在集合中
                return true;   // 说明有重复，直接返回 true
            }
            seen.insert(num);  // 否则将当前数字加入集合
        }
        return false;
    }
};