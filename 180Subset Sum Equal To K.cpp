
bool subsetSumToK(int n, int k, vector < int > & arr) {
    // Declaring dp array.
    vector < vector < bool >> dp(n + 1, vector < bool > (k + 1));

    // If required price = 0, answer always true.
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // If size of array = 0, answer always false.
    for (int i = 1; i <= k; i++) {
        dp[0][i] = false;
    }

    // Filling dp array.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    return dp[n][k];
}