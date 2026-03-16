class Solution {
public:
    int reverseBits(int n) {
        unsigned int x = static_cast<unsigned int>(n); // 当作无符号处理
        /*C++ 中，int 类型右移时，对于负数（最高位为 1），会进行算术右移，
        即高位补 1，而不是补 0。这会导致我们无法正确取出每一位*/

        unsigned int res = 0;
        for (int i = 0; i < 32; ++i) {
            res <<= 1; // 为下一位腾出空间
            res |= (x & 1);  // 取出最低位并放入结果
            x >>= 1; // 准备处理下一位
        }
        return static_cast<int>(res); // 位模式不变，强制转换回 int
    }
};