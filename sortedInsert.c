typedef struct DoublyLinkedListNode{
    int data;
    struct DoublyLinkedListNode* next;
    struct DoublyLinkedListNode* prev;
}DoublyLinkedListNode;


DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode * tmp = llist, * prev = llist;
    DoublyLinkedListNode * new_node = (DoublyLinkedListNode*)malloc(sizeof(DoublyLinkedListNode));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    while(tmp){
        if(tmp->data < data){
            if(tmp->prev == NULL){
                prev = tmp;
            }else{
                prev = prev->next;
            }
            if(tmp->next)
                tmp = tmp->next;
            else{
                tmp->next = new_node;
                new_node->prev = tmp;
                new_node->next = NULL;
                break;
            }
        }else{
            if(prev == tmp){
                 new_node->next = tmp;
                 tmp->prev = new_node;
                 llist = new_node;
                 break;
            }else {
                prev->next = new_node;
                new_node->prev = prev;
                new_node->next = tmp;
                tmp->prev = new_node;
            }
            break;
        }
    }
    return llist;
}
