class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;
        int n0 = zero, n1 = one;
        // pre1[i][j] = sum_{k=0..i} dp1[k][j]  (mod MOD)
        vector<vector<long long>> pre1(n0 + 1, vector<long long>(n1 + 1, 0));
        
        // Initialize the first row (i = 0): all sequences consisting only of 1's.
        for (int t = 1; t <= min(limit, n1); ++t) {
            pre1[0][t] = 1;          // dp1[0][t] = 1
        }

        // Process rows i = 1 .. n0-1 (all rows except the last one)
        for (int i = 1; i < n0; ++i) {
            vector<long long> dp0_row(n1 + 1, 0);
            vector<long long> dp1_row(n1 + 1, 0);
            
            // j = 0: only all-zero sequences are possible
            if (i <= limit) dp0_row[0] = 1;
            
            // Prefix sums of dp0 on the current row (for fast queries of dp1)
            vector<long long> pref0(n1 + 1, 0);
            pref0[0] = dp0_row[0];
            
            for (int j = 1; j <= n1; ++j) {
                // dp0[i][j] = sum_{t=1..min(limit,i)} dp1[i-t][j]
                long long sum0 = pre1[i-1][j];
                int prev = i - limit - 1;
                if (prev >= 0) {
                    sum0 -= pre1[prev][j];
                }
                sum0 %= MOD;
                if (sum0 < 0) sum0 += MOD;
                dp0_row[j] = sum0;
                
                // Update prefix sum for current row
                pref0[j] = (pref0[j-1] + dp0_row[j]) % MOD;
                
                // dp1[i][j] = sum_{t=1..min(limit,j)} dp0[i][j-t]
                long long sum1 = pref0[j-1];
                int prev_j = j - limit - 1;
                if (prev_j >= 0) {
                    sum1 -= pref0[prev_j];
                }
                sum1 %= MOD;
                if (sum1 < 0) sum1 += MOD;
                dp1_row[j] = sum1;
            }
            
            // Update the vertical prefix sums with the current row's dp1 values
            for (int j = 0; j <= n1; ++j) {
                pre1[i][j] = (pre1[i-1][j] + dp1_row[j]) % MOD;
            }
        }
        
        // Process the last row i = n0 (the row we need for the answer)
        int i = n0;
        vector<long long> dp0_last(n1 + 1, 0);
        vector<long long> dp1_last(n1 + 1, 0);
        if (i <= limit) dp0_last[0] = 1;
        
        vector<long long> pref0(n1 + 1, 0);
        pref0[0] = dp0_last[0];
        
        for (int j = 1; j <= n1; ++j) {
            // dp0[n0][j]
            long long sum0 = pre1[i-1][j];
            int prev = i - limit - 1;
            if (prev >= 0) {
                sum0 -= pre1[prev][j];
            }
            sum0 %= MOD;
            if (sum0 < 0) sum0 += MOD;
            dp0_last[j] = sum0;
            
            pref0[j] = (pref0[j-1] + dp0_last[j]) % MOD;
            
            // dp1[n0][j]
            long long sum1 = pref0[j-1];
            int prev_j = j - limit - 1;
            if (prev_j >= 0) {
                sum1 -= pref0[prev_j];
            }
            sum1 %= MOD;
            if (sum1 < 0) sum1 += MOD;
            dp1_last[j] = sum1;
        }
        
        long long ans = (dp0_last[n1] + dp1_last[n1]) % MOD;
        return (int)ans;
    }
};