SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

void reversePrint(SinglyLinkedListNode* llist) {
    size_t reverse_size = 10;
    int counter = 0;
    int * reverse_array = (int*)malloc(reverse_size * sizeof(int));
    SinglyLinkedListNode * tmp = llist;
    while(tmp != NULL){
        reverse_array[counter] = tmp->data;
        if(counter + 1 == reverse_size){
            reverse_size *= 2;
            reverse_array = (int*)realloc(reverse_array, reverse_size * sizeof(int));
        }
        ++counter;
        tmp = tmp->next;
    }
    --counter;
    for(; counter > -1; --counter){
        printf("%d\n", reverse_array[counter]);
    }
    free(reverse_array);
}
