typedef struct SinglyListNode{
  int data;
  struct SinglyListNode * next;
}SinglyListNode;

typedef struct Pair{
     SinglyLinkedListNode * node;
     int data;
}Pair;
 
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode * tmp_1 = head1, * tmp_2 = head2;
    SinglyLinkedListNode * new_head = NULL, * tail = NULL;

    size_t size_pairs_1 = 2000, size_pairs_2 = 2000;
    int counter_1 = 0, counter_2 = 0;
    Pair * pairs_1 = (Pair*)malloc(size_pairs_1 * sizeof(Pair));
    Pair * pairs_2 = (Pair*)malloc(size_pairs_2 * sizeof(Pair));

    while(tmp_1 != NULL || tmp_2 != NULL){
        if(tmp_1 != NULL){
            pairs_1[counter_1].data = tmp_1->data;
            pairs_1[counter_1].node = tmp_1;
            ++counter_1;
            tmp_1 = tmp_1->next;
        }
        if(tmp_2 != NULL){
            pairs_2[counter_2].data = tmp_2->data;
            pairs_2[counter_2].node = tmp_2;
            ++counter_2;
            tmp_2 = tmp_2->next;
        }
    }

    int iterator_1 = 0, iterator_2 = 0;
    while(iterator_1 != counter_1 || iterator_2 != counter_2){
        
        if(iterator_1 != counter_1 && iterator_2 != counter_2){
            if(pairs_1[iterator_1].data == pairs_2[iterator_2].data){
                if(new_head == NULL){
                    new_head = pairs_1[iterator_1].node;
                    tail = pairs_1[iterator_1].node;
                    tail->next = pairs_2[iterator_2].node;
                    tail = tail->next;
                }else{
                    tail->next = pairs_1[iterator_1].node;
                    tail = tail->next;
                    tail->next = pairs_2[iterator_2].node;
                    tail = tail->next;
                }
                ++iterator_1;
                ++iterator_2;
            }else if(pairs_1[iterator_1].data > pairs_2[iterator_2].data){
                if(new_head == NULL){
                    new_head = pairs_2[iterator_2].node;
                }else{
                    tail->next = pairs_2[iterator_2].node;
                }
                tail = pairs_2[iterator_2].node;
                ++iterator_2;
            }else{
                if(new_head == NULL){
                    new_head = pairs_1[iterator_1].node;
                }else{
                    tail->next = pairs_1[iterator_1].node;
                }
                tail = pairs_1[iterator_1].node;
                ++iterator_1;
            }
        }

        else if(iterator_1 == counter_1){
            while(iterator_2 != counter_2){
                tail->next = pairs_2[iterator_2].node;
                tail = tail->next;
                ++iterator_2;
            }
        }else if(iterator_2 == counter_2){
            while(iterator_1 != counter_1){
                tail->next = pairs_1[iterator_1].node;
                tail = tail->next;
                ++iterator_1;
            }
        }else{
            break;
        }
    }
    free(pairs_1);
    free(pairs_2);
    return new_head;
}
