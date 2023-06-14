

void inorder(TreeNode<int>* root, vector<int>& inTraversal)
{
	if (root == NULL)
	{
		return;
	}

	// Recurse over left subtree. 
	inorder(root -> left, inTraversal);

    inTraversal.push_back(root -> data);

	// Recurse over right subtree.
	inorder(root -> right, inTraversal);
}


int KthLargestNumber(TreeNode<int>* root, int k)
{
	vector <int> inTraversal;

	inorder(root, inTraversal);

	int n = inTraversal.size();

	if (k > n)
	{
		return -1;
	}
	
	return inTraversal[n - k];
}