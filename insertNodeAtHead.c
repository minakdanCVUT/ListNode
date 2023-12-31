SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    SinglyLinkedListNode * new_node = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    new_node->data = data;
    new_node->next = NULL;
    if(llist == NULL){
        llist = new_node;
    }else{
        new_node->next = llist;
        llist = new_node;
    }
    return llist;
}
