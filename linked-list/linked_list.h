#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Node of the linked list
typedef struct ListNode{
    struct ListNode* next;
    struct ListNode* prev;
    void* data;
} ListNode;

// Function definitions
int init_list();
ListNode* make_new_node();
size_t get_size_of_list();
int add_node(ListNode* listNode);

#endif