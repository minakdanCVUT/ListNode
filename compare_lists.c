SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode * tmp_1 = head1, * tmp_2 = head2;
    while(tmp_1 != NULL || tmp_2 != NULL){
        if((tmp_1 == NULL && tmp_2 != NULL) || (tmp_1 != NULL && tmp_2 == NULL)){
            return false;
        }
        else if(tmp_1->data != tmp_2->data){
            return false;
        }
        tmp_1 = tmp_1->next;
        tmp_2 = tmp_2->next;
    }
    return true;
}
