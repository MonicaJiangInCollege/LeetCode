class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.length();
        int count = 0;
        int current = length - 1;
        while (s[current] == ' ') {
            current--;
        }
        while (s[current] != ' ') {
            count++;
            if (current > 0) {
                current--;
            }
            if (current == 0) {
                return count;
            }
        }
        return count;
    }
};