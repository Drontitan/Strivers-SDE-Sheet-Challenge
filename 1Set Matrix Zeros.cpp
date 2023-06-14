
void setZeros(vector<vector<int>> &matrix)
{
	// Storing dimensions of matrix in n and m.
	int n = matrix.size();
	int m = matrix[0].size();
	
	// Declaring two boolean variables firstColZero and firstRowZero.
	bool firstColZero = false, firstRowZero = false;
	
	// Setting firstColZero to true if any element in first column is zero.
	for(int i = 0; i < n; i++) {
		if(matrix[i][0] == 0) {
			firstColZero = true;
			break;
		}
	}
	
	// Setting firstRowZero to true if any element in first row is zero.
	for(int j = 0; j < m; j++) {
		if(matrix[0][j] == 0) {
			firstRowZero = true;
			break;
		}
	}
	
	// Setting values for each row and column to be zero or not.
	for(int i = 1; i < n; i++) {
		for(int j = 1; j < m; j++) {
			if(matrix[i][j] == 0) {
				matrix[i][0] = matrix[0][j] = 0;
			}
		}
	}
	
	// If any element of first row is zero then that complete column should be zero and vice-versa.
	for(int i = 1; i < n; i++) {
		for(int j = 1; j < m; j++) {
			if(matrix[i][0] == 0 || matrix[0][j] == 0) {
				matrix[i][j] = 0;
			}
		}
	}
	
	// Setting first row to zero if firstRowZero is true.
	if(firstColZero) {
		for(int i = 0; i < n; i++) {
			matrix[i][0] = 0;
		}
	}
	
	// Setting first column to zero if firstColZero is true.
	if(firstRowZero) {
		for(int j = 0; j < m; j++) {
			matrix[0][j] = 0;
		}
	}
}
