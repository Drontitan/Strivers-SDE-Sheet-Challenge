

bool isBST(TreeNode<int>* root, int min, int max)
{
	if (root == NULL)
	{
		return true;
	}

	if (root -> data < min || root -> data > max)
	{
		return false;
	}

	return isBST(root -> left, min, root -> data - 1) && 
		   isBST(root -> right, root -> data + 1, max);
}


int size(TreeNode<int>* root)
{
	if (root == NULL)
	{
		return 0;
	}
	
	return 1 + size(root -> left) + size(root -> right);
}


int largestBST(TreeNode<int>* root)
{
	// Current Subtree is BST.
	if (isBST(root, INT_MIN, INT_MAX) == true)
	{
		return size(root);
	}
	
	// Find largest BST in left and right subtrees.
	return max(largestBST(root -> left), largestBST(root -> right));
}