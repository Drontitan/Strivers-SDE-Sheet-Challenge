

vector<int> subsetSum(vector<int> &num)
{
    int n = num.size();
    // Ans vector contains all the subset sums.
    vector<int> ans;

    for (int i = 0; i < (1 << n); i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            // Checking wheather the element is present the subset or not.
            if ((1 << j) & i)
            {
                sum += num[j];
            }
        }
        ans.push_back(sum);
    }
    // Sort the vector and finally return it.
    sort(ans.begin(), ans.end());
    return ans;
}