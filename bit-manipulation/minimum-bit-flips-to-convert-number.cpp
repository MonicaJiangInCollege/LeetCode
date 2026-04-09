class Solution {
public:
    int minBitFlips(int start, int goal) {
        // 异或得到不同位的掩码
        int diff = start ^ goal;
        // 统计 diff 中 1 的个数，即不同位的数量
        return __builtin_popcount(diff);
    }
};