SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode * tmp = llist;
    size_t reverse_size = 10;
    int counter = 0;
    int * reverse_arr = (int*)malloc(reverse_size  * sizeof(int));
    while(tmp != NULL){
        reverse_arr[counter] = tmp->data;
        if(counter + 1 == reverse_size){
            reverse_size *= 2;
            reverse_arr = (int*)realloc(reverse_arr, reverse_size * sizeof(int));
        }
        ++counter;
        tmp = tmp->next;
    }
    --counter;
    tmp = llist;
    while(tmp != NULL){
        tmp->data = reverse_arr[counter];
        --counter;
        tmp = tmp->next;
    }
    return llist;
}
