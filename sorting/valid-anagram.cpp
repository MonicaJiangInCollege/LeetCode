class Solution {
public:
    bool isAnagram(string s, string t) {
        // 长度不同，肯定不是字母异位词
        if (s.length() != t.length()) return false;
        
        // 只有小写字母，使用大小为26的数组计数
        int count[26] = {0};
        
        // 统计s中每个字符的出现次数
        for (char c : s) {
            count[c - 'a']++;
        }
        
        // 遍历t，减去对应字符的计数
        for (char c : t) {
            count[c - 'a']--;
        }
        
        // 检查是否所有计数都归零
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }
        
        return true;
    }
};