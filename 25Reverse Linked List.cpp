

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {

    if (head == NULL || head->next == NULL) {
        return head;
    }

    LinkedListNode<int> *pre = NULL;
    while (head != 0) {

        pre = (LinkedListNode<int>*) ((uintptr_t) pre ^ (uintptr_t) head->next);
        head->next = (LinkedListNode<int>*) ((uintptr_t) pre ^ (uintptr_t) head->next); 
        pre = (LinkedListNode<int>*) ((uintptr_t) pre ^ (uintptr_t) head->next);       
 
        pre = (LinkedListNode<int>*) ((uintptr_t) pre ^ (uintptr_t) head);
        head = (LinkedListNode<int>*) ((uintptr_t) pre ^ (uintptr_t) head);
        pre = (LinkedListNode<int>*) ((uintptr_t) pre ^ (uintptr_t) head);

    }

    return pre;

}