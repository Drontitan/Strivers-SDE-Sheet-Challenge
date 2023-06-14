

int removeDuplicates(vector<int> &arr, int n) {
    // First pointer.
    int i = 0;

    // Second pointer traversing from 1 to n.
    for (int j = 1; j < n; j++) {
        //  If not duplicates increment first pointer and check again.
        if (arr[j] != arr[j-1]) {
            arr[i++] = arr[j];
        }
    }
    // Return length == (index of first pointer when second reaches end) + 1.
    return i + 1;
}