class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};
        // 统计每个字符出现的次数
        for (char c : s) {
            freq[c - 'a']++;
        }
        // 找到第一个出现次数为1的字符
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};