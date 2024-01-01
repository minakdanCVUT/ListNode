typedef struct SinglyListNode{
  int data;
  struct SinglyListNode * next;
}SinglyListNode;

int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    size_t arr_size = 1001;
    int counter = 0;
    int * arr = (int*)malloc(arr_size * sizeof(int));
    SinglyLinkedListNode * tmp = llist;
    while(tmp){
        arr[counter++] = tmp->data;
        tmp = tmp->next;
    }
    int res = arr[counter - 1 - positionFromTail];
    free(arr);
    return res;
}
