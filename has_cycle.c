typedef struct SinglyListNode{
  int data;
  struct SinglyListNode * next;
}SinglyListNode;

bool has_cycle(SinglyLinkedListNode* head) {
    size_t size_for = 1001;
    SinglyLinkedListNode ** arr_pointers = (SinglyLinkedListNode**)malloc(size_for * sizeof(SinglyLinkedListNode*));
    int counter = 0;
    SinglyLinkedListNode * tmp = head;
    while(tmp){
        if(counter == 0){
            arr_pointers[counter] = tmp;
            ++counter;
        }else{
            arr_pointers[counter] = tmp;
            ++counter;
            for(int i = 0; i < counter; ++i){
                if(tmp->next){
                    if(arr_pointers[i] == tmp->next){
                        return true;
                    }
                }else{
                    break;
                }
            }
        }
        tmp = tmp->next;
    }
    return false;
}
