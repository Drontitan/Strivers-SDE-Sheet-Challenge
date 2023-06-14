
TreeNode<int>* convert (vector<int> &arr, int start, int end)
{
    // Base case.
    if(start > end)
    {
        return NULL;
    }

    else
    {
        // Find 'mid' index of array and make it root node. 
        int mid = (start+end)/2;
        TreeNode<int>* rootNode = new TreeNode<int>(arr[mid]);

        // Call 'convert' function for the left part of array to make leftSubtree of root node.
        rootNode -> left = convert(arr,start,mid-1);

        // Call 'convert' function for the right part of array to make rightSubtree of root node.
        rootNode -> right = convert(arr,mid+1,end);

        // Return the rootNode.
        return rootNode;
    }
}


TreeNode<int>* sortedArrToBST (vector<int> &arr, int n)
{
    // Call the recursive function to convert array into tree.
    TreeNode<int>* root = convert(arr, 0, n-1);

    // Return the root node of tree.
    return root;
}