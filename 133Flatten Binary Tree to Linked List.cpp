
void preOrderTraversal(TreeNode<int> *root, vector<int> &preOrder)
{
    if (root == NULL)
        return;

    preOrder.push_back(root->data);

    preOrderTraversal(root->left, preOrder);
    preOrderTraversal(root->right, preOrder);
}

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    vector<int> preOrder;

    // Find the pre-order traversal of the tree and store it in a list.
    preOrderTraversal(root, preOrder);

    // Create a new linked list from the stored values.
    TreeNode<int> *head = root;

    for (int i = 1; i < preOrder.size(); i++)
    {
        root->right = new TreeNode<int>(preOrder[i]);

        root = root->right;
    }

    return head;
}
