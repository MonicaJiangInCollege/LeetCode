class Solution {
public:
    bool isPowerOfThree(int n) {
        // 非正数不可能是3的幂
        if (n <= 0) return false;
        // 不断除以3，直到不能被3整除
        while (n % 3 == 0) {
            n /= 3;
        }
        // 如果最后剩下1，说明原数是3的幂
        return n == 1;
    }
};