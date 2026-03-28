class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // 1. 分割字符串 s 为单词列表
        vector<string> words;
        stringstream ss(s);      // 创建字符串流，用于按空格读取
        string word;
        while (ss >> word) {     // 每次读取一个单词（以空格分隔）
            words.push_back(word);
        }
        
        // 2. 长度不匹配直接返回 false
        if (pattern.size() != words.size()) {
            return false;
        }
        
        // 3. 建立两个哈希表
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        
        // 4. 遍历所有位置
        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            string w = words[i];
            
            // 检查字符映射是否冲突
            if (charToWord.count(c) && charToWord[c] != w) {
                return false;
            }
            // 检查单词映射是否冲突
            if (wordToChar.count(w) && wordToChar[w] != c) {
                return false;
            }
            
            // 建立映射（如果之前不存在就创建，如果存在且相同，这里相当于覆盖，但不影响）
            charToWord[c] = w;
            wordToChar[w] = c;
        }
        
        return true;
    }
};