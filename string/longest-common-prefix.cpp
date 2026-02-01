class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        else {
            string prefix = "";
            // 以第一个字符串为基准
            for (int i = 0; i < strs[0].length(); i++) {
                char current = strs[0][i];
                for (int j = 0; j < strs.size(); j++) {
                    if (strs[j][i] != strs[0][i]||i>strs[j].length()) {
                        return prefix;
                    }
                }
                prefix += current;
            }
            return prefix;
        }
    }
};