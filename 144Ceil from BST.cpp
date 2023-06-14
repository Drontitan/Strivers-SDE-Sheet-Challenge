
int findCeil(BinaryTreeNode < int > * node, int x) {
  // Initializing ceil value
  int ceil = -1;

  // Traverse till the node is not null
  while (node != NULL) {

    // If node value equals key then return it
    if (x == node -> data) {
      return node -> data;
    }

    // Traverse right sub-tree
    if (x > node -> data) {

      node = node -> right;
    }

    // Traverse left sub-tree
    else {
      ceil = node -> data;
      node = node -> left;
    }
  }

  // Return the ceil value
  return ceil;

}