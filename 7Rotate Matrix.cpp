
void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Index of starting row and column
    int rowStart = 0, colStart = 0; 
    
    int previous, current; 

    while (rowStart < n && colStart < m) 
    { 
        // If we have rotated the whole matrix
        if (rowStart == n - 1 || colStart == m - 1)
        { 
            break; 
        }
        // Store the first element of next rown as this element will replace the first element of current row
        previous = mat[rowStart + 1][colStart]; 
        
        // Move elements of first row from the remaining rows
        for (int i = colStart; i < m; i++) 
        { 
            current = mat[rowStart][i]; 
            mat[rowStart][i] = previous; 
            previous = current; 
        } 
        rowStart++; 
  
        // Move elements of last column from the remaining columns 
        for (int i = rowStart; i < n; i++) 
        { 
            current = mat[i][m-1]; 
            mat[i][m-1] = previous; 
            previous = current; 
        } 
        m--; 
  
        // Move elements of last rowStart from the remaining rows 
        if (rowStart < n) 
        { 
            for (int i = m-1; i >= colStart; i--) 
            { 
                current = mat[n-1][i]; 
                mat[n-1][i] = previous; 
                previous = current; 
            } 
        } 
        n--; 
  
        // Move elements of first column from the remaining rows 
        if (colStart < m) 
        { 
            for (int i = n-1; i >= rowStart; i--) 
            { 
                current = mat[i][colStart]; 
                mat[i][colStart] = previous; 
                previous = current; 
            } 
        } 
        colStart++; 
    } 
}