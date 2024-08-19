class Solution {
public:
    int minSteps(int n) {
        if (n <= 1)
            return 0;
        vector<int> dp(n + 1, n);
        dp[1] = 0;
        for (int i = 2; i <= n; ++i)
            for (int factor = 1; factor <= i / 2; factor++)
                if (i % factor == 0)
                    dp[i] = min(dp[i], dp[factor] + (i / factor));
        return dp[n];
    }
};