typedef struct SinglyListNode{
  int data;
  struct SinglyListNode * next;
}SinglyListNode;


SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode * tmp = llist, * duplicate = NULL;
    while(tmp){
        if(tmp->next){
            if(tmp->data == tmp->next->data){
                duplicate = tmp->next;
                tmp->next = duplicate->next;
                free(duplicate);
            }else{
                tmp = tmp->next;
            }
        }else{
            break;
        }   
    }
    return llist;
}
