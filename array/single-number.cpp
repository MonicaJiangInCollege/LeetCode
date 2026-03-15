class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;  // 异或运算：相同为0，不同为1
        }
        return result;
    }
};