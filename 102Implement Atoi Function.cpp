
int atoi(string str) {
    bool isNegative = 0;

    // Check Negative.
    if (str[0] == '-') {
        isNegative = 1;
    }

    int number = 0;
    for (int i = 0; i < str.size(); i++) {

        // If the charecter is a digit.
        if (str[i] >= '0'
            and str[i] <= '9') {
            int digit = (char) str[i] - '0';
            number = number * 10 + digit;
        }
    }

    if (isNegative) {
        number *= -1;
    }

    return number;
}