int coinChange(vector<int>& coins, int amount) {
    const int maxn = 1e4 + 5;
    const int INF = 1e4 + 5;
    int dp[maxn];
    for (int i = 0; i < maxn; i++) dp[i] = INF;
    dp[0] = 0;
    int n = coins.size();
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            int pre = i - coins[j];
            if (pre < 0) continue;
            else dp[i] = min(dp[i], dp[pre] + 1);
        }
    }
    return dp[amount] == INF ? -1 : dp[amount];
}