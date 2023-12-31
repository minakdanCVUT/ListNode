SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

void printLinkedList(SinglyLinkedListNode* head) {
    SinglyLinkedListNode * tmp = head;
    while(tmp != NULL){
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
}
