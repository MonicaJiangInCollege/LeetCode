class Solution {
public:
    int bitwiseComplement(int n) {
        // 特殊情况：n == 0，二进制 "0" 的补数是 "1"，即 1
        if (n == 0) return 1;
        // 构造与 n 二进制位数相同且全为 1 的掩码
        int mask = 0;
        int temp = n;
        while (temp) {
            mask = (mask << 1) | 1;
            temp >>= 1;
        }
        // 异或得到按位取反的结果
        return n ^ mask;
    }
};