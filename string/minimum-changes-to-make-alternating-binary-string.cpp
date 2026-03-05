class Solution {
public:
    int minOperations(string s) {
        int count = 0;
        int length = s.size();
        int start0 = 0; // number of operations needed for string that starts with 0
        int start1 = 0; // number of operations needed for string that starts with 1

        char expected0 = '0';
        char expected1 = '1';

        for (int i = 0; i < length; i++) {
            if (i % 2 == 0) {
                expected0 = '0';
                expected1 = '1';
            }
            else {
                expected0 = '1';
                expected1 = '0';
            }
            if (expected0 != s[i])
                start0++;
            if (expected1 != s[i])
                start1++;
        }
        if (start0 < start1)
            count = start0;
        else
            count = start1;

        return count;
    }
};