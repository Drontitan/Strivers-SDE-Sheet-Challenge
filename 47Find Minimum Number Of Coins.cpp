

int findMinimumCoins(int amount) 
{
	// Array to store denominations.
	vector<int> denominations = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
	
	// Variable to store result.
    int coinsCount = 0; 
    int n = denominations.size();

    // Pick coins in decreasing order of their values
    for (int i = n - 1; i >= 0; i--) 
    {
        coinsCount += amount / denominations[i];
        amount %= denominations[i];
    }

    return coinsCount; 
} 
