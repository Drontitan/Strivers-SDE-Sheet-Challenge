/*
    Time Complexity : O(n) 
    Space Complexity: O(1)
    
    Where n denotes the size of the linked list.
*/

/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
    
    // Base condition.
    if(head == NULL) {
        return head;
    }
    
    int len = 1;
    Node *temp = head;
        
    // Calculate length of the linked list.
    while(temp->next != NULL) {
        temp = temp->next;
        len += 1;
    }
    
    k = k % len;
    
    // Number of rotations are same as len so no change in LL.
    if(k == len || k == 0) {
        return head;
    }

    // To make a circular linked list.
    temp->next = head;

    temp = head;
    
    for(int i = 0; i < abs(len - k - 1); i++) {
        temp = temp->next;
    }

    // Changing pointers.
    head = temp->next;
    temp->next = NULL;

    return head;
}
