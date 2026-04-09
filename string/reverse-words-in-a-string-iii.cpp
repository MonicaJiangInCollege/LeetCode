class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int start = 0;
        for (int i = 0; i <= n; ++i) {
            // When we hit a space or end of string, reverse the current word
            if (i == n || s[i] == ' ') {
                // Reverse the word from start to i-1
                int left = start, right = i - 1;
                while (left < right) {
                    swap(s[left], s[right]);
                    left++;
                    right--;
                }
                // Move start to the next character after the space
                start = i + 1;
            }
        }
        return s;
    }
};