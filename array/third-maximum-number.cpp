class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // 使用 long 类型初始化为最小可能值，避免与数组中的 INT_MIN 冲突
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
        for (int num : nums) {
            // 跳过重复的数字
            if (num == first || num == second || num == third) continue;
            
            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second) {
                third = second;
                second = num;
            } else if (num > third) {
                third = num;
            }
        }
        // 如果第三大不存在，返回最大值；否则返回第三大
        return third == LONG_MIN ? first : third;
    }
};