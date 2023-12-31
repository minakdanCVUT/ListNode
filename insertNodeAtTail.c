SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode * tmp = head;
    SinglyLinkedListNode * new_node = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    new_node->data = data;
    new_node->next = NULL;
    if(tmp == NULL){
        tmp = new_node;
        head = tmp;
    }else{
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = new_node;
    }
    return head;
}
