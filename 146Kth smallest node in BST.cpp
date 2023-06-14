

#include <stack>

int kthSmallest(TreeNode<int> *root, int k)
{
	//	To store the nodes of the tree.
	stack<TreeNode<int> *> st;

	while (1)
	{
		while (root != NULL)
		{
			//	Push the root node in the stack.
			st.push(root);

			root = root->left;
		}

		root = st.top();
		st.pop();

		if (k == 1)
		{
			return root->data;
		}

		//	Update the 'k'
		k = k - 1;

		root = root->right;
	}
}