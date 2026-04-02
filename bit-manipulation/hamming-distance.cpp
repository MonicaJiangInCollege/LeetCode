class Solution {
public:
    int hammingDistance(int x, int y) {
    int xorVal = x ^ y;          // 异或，不同位为1
    return __builtin_popcount(xorVal); // 统计1的个数
}
};