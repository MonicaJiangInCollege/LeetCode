class Solution {
public:
    int climbStairs(int n) {
        // actually a Fibonacci number array
        if (n == 1)
            return 1;
        else if (n == 2)
            return 2;
        else {
            int num1 = 1;
            int num2 = 2;
            for (int i = 3; i <= n; i++) {
                int current = num1 + num2;
                num1 = num2;
                num2 = current;
            }
            return num2;
        }
    }
};