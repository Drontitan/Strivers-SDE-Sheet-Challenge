

vector<int> getLeftView(TreeNode<int> *root)
{
    
    //    For storing the left view.
    vector<int> leftView;

    if (root == NULL)
    {
        return leftView;
    }

    //    Queue for doing level order traversal.
    queue<TreeNode<int> *> level;

    //    Push the root in the queue.
    level.push(root);
    int leftMostNode;

    while (level.empty() == false)
    {
        
        //    Get the size of the current level.
        int queueSize = level.size();

        //    Traverse all nodes of the current level.
        for (int i = 0; i < queueSize; i++)
        {
            
            //    Pop the node from the front of the queue.
            TreeNode<int> *curr = level.front();
            level.pop();

            //    Store the left most node of the current level.
            if (i == 0)
            {
                leftMostNode = curr->data;
            }

            //    Push the left child into the queue.
            if (curr->left != NULL)
            {
                level.push(curr->left);
            }

            //    Push the right child into the queue.
            if (curr->right != NULL)
            {
                level.push(curr->right);
            }
        }

        //    Store the left most node of the current level in the array.
        leftView.push_back(leftMostNode);
    }

    //    Return the left view of the given binary tree.
    return leftView;
}