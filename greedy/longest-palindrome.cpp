class Solution {
public:
    int longestPalindrome(string s) {
        // 使用数组统计每个字符的出现次数（ASCII 范围足够）
        vector<int> count(128, 0);
        for (char c : s) {
            count[c]++;
        }
        int length = 0;
        bool hasOdd = false;
        for (int freq : count) {
            if (freq % 2 == 0) {
                length += freq;          // 偶数个可以全部使用
            } else {
                length += freq - 1;      // 奇数个只能使用偶数部分
                hasOdd = true;           // 标记存在奇数个的字符
            }
        }
        // 如果存在奇数个的字符，可以放一个在中心
        if (hasOdd) length++;
        return length;
    }
};