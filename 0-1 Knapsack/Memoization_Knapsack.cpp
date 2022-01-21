int Knapsack(vector<int> wt, vector<int> val, int W, int n) {
    int dp[n+1][W+1];
    memset(dp, -1, sizeof(dp));
    if(n==0 || W==0) {
        return 0;
    }
    if(dp[n][W] != -1) {
        return dp[n][W];
    }
    if(wt[n-1] <= W) {
        dp[n][W] = max((val[n-1] + Knapsack(wt, val, W-wt[n-1], n), Knapsack(wt, val, W, n-1)));
    } else if((wt[n-1] >= W)) {
        dp[n][W] = Knapsack(wt, val, W, n);
    }
    return dp[n][W];
}