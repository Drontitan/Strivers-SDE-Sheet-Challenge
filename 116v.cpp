

#include <map>

void applyPreOrder(TreeNode<int> *root, int hDistance, int level, map<int, pair<int, int>> &visited) {
    // Base Case.
    if (root == NULL) {
        return;
    }

    auto x = visited.find(hDistance);

    // Check whether the current horizontal distance is already visited or not?
    // If visited then is previous visited element has greater level.
    if (x == visited.end() || (x->second).second > level) {
        visited[hDistance] = {root->val, level};
    }

    // Go for left subtree with one less horizontal distance and one more level.
    applyPreOrder(root->left, hDistance - 1, level + 1, visited);

    // Go for right subtree with one more horizontal distance and one more level.
    applyPreOrder(root->right, hDistance + 1, level + 1, visited);
}

vector<int> getTopView(TreeNode<int> *root) {
    // To store horizontal distance as a key and pair of node's value and it's level as the value.
    map<int, pair<int, int>> visited;

    // Apply pre-order with 0 horizontal distance and 0 levels for root.
    applyPreOrder(root, 0, 0, visited);

    // Get the top view of the tree.
    vector<int> topView;

    // Add the nodes sorted by key into the vector topview.
    for (auto view : visited) {
        topView.push_back(view.second.first);
    }

    // Return the answer sequence of nodes.
    return topView;
}