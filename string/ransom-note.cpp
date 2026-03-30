class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26] = {0}; // 统计 magazine 中每个字母的出现次数
        for (char c : magazine) {
            count[c - 'a']++;
        }
        for (char c : ransomNote) {
            if (--count[c - 'a'] < 0) {
                return false; // 字母不够用
            }
        }
        return true;
    }
};