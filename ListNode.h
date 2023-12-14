#include <iostream>
struct ListNode{
  int val;
  ListNode * next;
};

void initListNode(ListNode & node);

void printList(ListNode & node);

void addToList(ListNode & node, const int val);

ListNode * deleteFromTheList(ListNode & node, ListNode ** head, const int index);










