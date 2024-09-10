#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

ListNode* head;
ListNode* tail;


int init_list()
{
    return 0;
}

ListNode* make_new_node()
{
    // Generate a new node, set parameters to default
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) 
    {
        return NULL; // Return an error code if malloc fails
    }
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = NULL;
    return newNode;
}

size_t get_size_of_list()
{   
    // Even any nodes?
    if (head == NULL)
    {
        return 0;
    }

    // Iterate the list
    ListNode* currentNode = head;
    size_t listSize = 0;
    
    // Iterate from back to front
    while (currentNode != NULL)
    {
        currentNode = currentNode->next;
        ++listSize;
    }

    return listSize;
}

int add_node(ListNode* listNode)
{
    // Set the head's previous owner's next node equal to this one
    if (get_size_of_list() == 0)
    {
        head = listNode;
        tail = listNode;
        return 0;
    }

    // Set the current head's next equal to this node's ptr
    head->next = listNode;
    // Set the new node's previous equal to the current head's ptr
    listNode->prev = head;
    // Set the new head of the list to be this new node
    head = listNode;
    return 0;
}