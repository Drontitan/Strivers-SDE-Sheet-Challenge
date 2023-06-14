
int NthRoot(int n, int m) {

    double error = 1e-2;

    // Difference between the current answer, and the answer
    // in next iteration, which we take as big as possible initially.
    double diff = 1e18;

    // Guessed answer value.
    double xk = 2;

    // We keep on finding the precise answer till the difference between
    // answer of two consecutive iteration become less than 10^(-7).
    while (diff > error) {

        // Answer value in the next iteration.
        double xk_1 = (pow(xk, n) * (n - 1) + m) / (n * pow(xk, n - 1));

        // Difference of answer in consecutive states updated.
        diff = abs(xk - xk_1);

        // Updating the current answer with the answer of next iteration.
        xk = xk_1;
    }

    // Extracting integer value from 'xk'
    int integerAns = (int) xk;

    // Checking whether nth Root exists or not
    int res = 1;
    for(int i = 0; i < n; ++i) {
      res *= integerAns;
    }
    
    if(res != m) {
      // Updating value of 'integerAns'
      integerAns = -1;
    }

    // Returning the nthRootOfM
    return integerAns;
}