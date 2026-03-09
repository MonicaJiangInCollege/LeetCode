class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;
        int Z = zero + 1;
        int O = one + 1;
        int L = limit + 1;                     // l ranges from 0 to limit
        int total = Z * O * 2 * L;              // total number of states
        vector<int> dp(total, 0);

        // helper to compute linear index
        auto idx = [&](int i, int j, int c, int l) -> int {
            return ((i * O + j) * 2 + c) * L + l;
            };

        // initial states: first element 0 or 1
        if (zero >= 1) {
            dp[idx(1, 0, 0, 1)] = 1;
        }
        if (one >= 1) {
            dp[idx(0, 1, 1, 1)] = 1;
        }

        // DP over number of 0's used (i) and 1's used (j)
        for (int i = 0; i <= zero; ++i) {
            for (int j = 0; j <= one; ++j) {
                for (int c = 0; c < 2; ++c) {          // last digit
                    for (int l = 1; l <= limit; ++l) { // current run length
                        int val = dp[idx(i, j, c, l)];
                        if (val == 0) continue;

                        if (c == 0) {
                            // append another 0
                            if (i + 1 <= zero && l + 1 <= limit) {
                                int nidx = idx(i + 1, j, 0, l + 1);
                                dp[nidx] = (dp[nidx] + val) % MOD;
                            }
                            // append a 1
                            if (j + 1 <= one) {
                                int nidx = idx(i, j + 1, 1, 1);
                                dp[nidx] = (dp[nidx] + val) % MOD;
                            }
                        }
                        else { // c == 1
                            // append another 1
                            if (j + 1 <= one && l + 1 <= limit) {
                                int nidx = idx(i, j + 1, 1, l + 1);
                                dp[nidx] = (dp[nidx] + val) % MOD;
                            }
                            // append a 0
                            if (i + 1 <= zero) {
                                int nidx = idx(i + 1, j, 0, 1);
                                dp[nidx] = (dp[nidx] + val) % MOD;
                            }
                        }
                    }
                }
            }
        }

        // sum all valid sequences that use exactly zero 0's and one 1's
        int ans = 0;
        for (int l = 1; l <= limit; ++l) {
            ans = (ans + dp[idx(zero, one, 0, l)]) % MOD;
            ans = (ans + dp[idx(zero, one, 1, l)]) % MOD;
        }
        return ans;
    }
};