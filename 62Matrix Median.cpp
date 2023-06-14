/*
    Time Complexity : O(N * M * log(N * M))
    Space Complexity : O(N * M)

    Where ‘N’ is the number of rows 
    and ‘M’ is the number of columns in the given matrix.
*/

#include <algorithm>

int getMedian(vector<vector<int>> &matrix)
{

    int n = matrix.size();
    int m = matrix[0].size();

    // Vector to store the elements in given matrix.
    vector<int> data;

    // Iterate through matrix and push elements in the vector.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            data.push_back(matrix[i][j]);
        }
    }

    // Sort the vector of elements in non-decreasing order.
    sort(data.begin(), data.end());

    // Return the median which is (N*M)/2 th element in the vector.
    return data[(n * m) / 2];
}