SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode * new_node = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    SinglyLinkedListNode * tmp = llist, * head = llist;
    new_node->data = data;
    new_node->next = NULL;
    if (position == 0) {
        new_node->next = llist;
        llist = new_node; 
    } else {
        int counter = 1;
        SinglyLinkedListNode *prev = llist;
        SinglyLinkedListNode *tmp = llist->next;

        while (tmp != NULL) { 
            if (counter == position) {
                prev->next = new_node;
                new_node->next = tmp;
                break;
            } else {
                ++counter;
                prev = prev->next;
                tmp = tmp->next;
            }
        }
    }
    return llist;
}
