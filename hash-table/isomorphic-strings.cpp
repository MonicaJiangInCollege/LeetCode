class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // 如果长度不同，肯定不同构（题目保证相等，但保留检查）
        if (s.length() != t.length()) return false;

        // 两个哈希表分别记录 s->t 和 t->s 的映射
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;

        for (int i = 0; i < s.length(); ++i) {
            char cs = s[i];
            char ct = t[i];

            // 检查 s->t 映射是否冲突
            if (s2t.find(cs) != s2t.end()) {
                if (s2t[cs] != ct) return false;
            } else {
                s2t[cs] = ct;
            }

            // 检查 t->s 映射是否冲突
            if (t2s.find(ct) != t2s.end()) {
                if (t2s[ct] != cs) return false;
            } else {
                t2s[ct] = cs;
            }
        }

        return true;
    }
};