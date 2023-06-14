/*
    Time Complexity: O(N)
    Space Compexity: O(N)

    Where 'N' is the total nodes in Linked List.
*/


Node* removeKthNode(Node* head, int K) {
    if (head == NULL) {
        return head;
    }

    vector<Node*> nodeList;
    Node* temp = head;

    // Traverse the linked list and add each node to the array
    while (temp != NULL) {
        nodeList.push_back(temp);
        temp = temp->next;
    }

    // If the head of the linked list is the Kth node
    if (K == nodeList.size()) {
        Node* next = head->next;
        head->next = NULL;
        delete head;
        head = next;
    } else {
        // Remove the Kth node from the end
        nodeList[nodeList.size() - K - 1]->next = nodeList[nodeList.size() - K]->next;
        
        delete nodeList[nodeList.size() - K];
    }
    return head;
}
