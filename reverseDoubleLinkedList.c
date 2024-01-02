typedef struct DoublyLinkedListNode{
    int data;
    struct DoublyLinkedListNode* next;
    struct DoublyLinkedListNode* prev;
}DoublyLinkedListNode;



DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    size_t arr_size = 1001;
    int counter = 0;
    Pair * arr = (Pair*)malloc(arr_size * sizeof(Pair));
    DoublyLinkedListNode * tmp = llist;
    while(tmp){
        arr[counter].node = tmp;
        arr[counter].data = tmp->data;
        ++counter;
        tmp = tmp->next;
    }
    --counter;
    DoublyLinkedListNode * new_head = NULL, * tail = NULL;
    for(int i = counter; i > -1; --i){
        if(new_head == NULL){
            new_head = arr[i].node;
            new_head->prev = NULL;
        }else{
            arr[i].node->prev = tail;
            tail->next = arr[i].node;
        }
        tail = arr[i].node;
        if(i == 0){
            tail->next = NULL;
        }
    }
    free(arr);
    return new_head;
}
