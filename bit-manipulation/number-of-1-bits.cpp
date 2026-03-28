class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n) {
            n &= (n - 1);  // 每次消除最低位的 1
            count++;
        }
        return count;
    }
};