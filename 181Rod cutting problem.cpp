

int cutRod(vector<int> &price, int n)
{
    int cost[n + 1];
    cost[0] = 0;
    int i, j;

    for (i = 1; i <= n; i++)
    {
        int maxCost = INT_MIN;

        // Build the table in bottom up manner.
        for (j = 0; j < i; j++)
        {
            maxCost = max(maxCost, price[j] + cost[i - j - 1]);
        }

        // Contains maximum cost obtained from the rod of length 'i'.
        cost[i] = maxCost;
    }

    // Last entry conatins maximum cost obtained from the rod of length 'n'.
    return cost[n];
}