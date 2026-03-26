class Solution {
public:
    class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;   // 丑数必须是正整数
        // 不断除以2、3、5
        while (n % 2 == 0) 
        n /= 2;
        while (n % 3 == 0) 
        n /= 3;
        while (n % 5 == 0) 
        n /= 5;
        return n == 1;              // 如果最后剩下1，说明质因子只有2、3、5
    }
};
};