SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    SinglyLinkedListNode * duplicate = NULL;
    if(position == 0){
        duplicate = llist;
        llist = llist->next;
    }else{
        SinglyLinkedListNode * prev = llist;
        SinglyLinkedListNode * current = llist->next;
        int counter = 1;
        while(true){
            if(counter == position){
                duplicate = current;
                prev->next = duplicate->next;
                break;
            }else{
                ++counter;
                prev = prev->next;
                current = current->next;
            }
        }
    }
    free(duplicate);
    return llist;
}
