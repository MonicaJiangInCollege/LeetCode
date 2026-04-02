class Solution {
public:
    int arrangeCoins(int n) {
        // 使用 long long 避免溢出
        long long total = (long long)n;
        // 解方程 k*(k+1)/2 <= n，即 k^2 + k - 2n <= 0
        // 求根公式：k = floor( (-1 + sqrt(1 + 8n)) / 2 )
        long long k = (sqrt(1 + 8 * total) - 1) / 2;
        return (int)k;
    }
};