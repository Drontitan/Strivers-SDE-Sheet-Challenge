/*
    Time Complexity: O(N * V)
    Space Complexity: O(V)
    
    where N is the length of denominations array and V is the value.

*/

long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Dp[i] will be storing the number of solutions for value i.
    long *dp = new long[value + 1]();
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = denominations[i]; j <= value; j++)
        {
            dp[j] += dp[j - denominations[i]];
        }
    }

    return dp[value];
}