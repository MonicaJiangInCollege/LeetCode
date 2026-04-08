class Solution {
public:
    bool checkPerfectNumber(int num) {
        // Perfect numbers must be greater than 1
        if (num <= 1) return false;
        int sum = 1; // 1 is always a proper divisor (except for num=1)
        // Iterate up to sqrt(num) to find all divisor pairs
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                sum += i;  // add the smaller divisor
                if (i != num / i) {   // avoid adding the square twice
                    sum += num / i;   // add the larger divisor
                }
            }
        }
        return sum == num;
    }
};