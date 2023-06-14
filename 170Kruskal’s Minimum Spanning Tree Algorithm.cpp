

#include <algorithm>

// Custom comparator to sort the edges.
bool compare(vector<int> const &a, vector<int> const &b) {
	return a[2] < b[2];
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Stores the number of the subtree to which a node belongs.
	vector<int> tree_id(n);
	for (int i = 1; i <= n; i++) {
		// Initially each node will be in seperate subtree.
		tree_id[i] = i;
	}

	// To store the weight of MST.
	int cost = 0;

	// Sort the edges in ascending order by its weight.
	sort(graph.begin(), graph.end(), compare);

	// Start traversign through the edges.
	for (auto edge : graph) {
		int u = edge[0];
		int v = edge[1];
		int w = edge[2];
		// Check if both vertices of current edge belong to different sets(subtrees).
		if (tree_id[u] != tree_id[v]) {
			// Add the weight of the current edge to 'cost'.
			cost += w;

			// Choose one of the tree_id values as our new common id.
			int new_id = tree_id[v];
			int old_id = tree_id[u];
			// Update the tree_id of vertices which belong to first vertex.
			for (int i = 1; i <= n; i++) {
				if (tree_id[i] == old_id) {
					// Vertex belongs to the set of vertex 'u'.
					tree_id[i] = new_id;
				}
			}
		}
	}
	return cost;
}