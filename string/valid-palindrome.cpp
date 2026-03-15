class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while (left < right) {
            // 跳过左指针的非字母数字字符
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            // 跳过右指针的非字母数字字符
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // 比较忽略大小写后的字符
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};