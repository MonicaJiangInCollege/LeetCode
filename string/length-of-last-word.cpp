class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.length();
        int count = 0;
        int current = length - 1;
        while (s[current] == ' ') {
            current--;
        }
        while ((current>=0)&&(s[current] != ' ') ){
            count++;
            current--;
        }
        return count;
    }
};