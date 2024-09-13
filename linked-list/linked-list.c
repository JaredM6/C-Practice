#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked-list.h"

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
    // Iterate the list (at least one node)
    ListNode* currentNode = head;
    size_t listSize = 0;
        
    while (currentNode != NULL)
    {
        currentNode = currentNode->prev;
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

int delete_node(ListNode* listNode)
{
    // Check for bad use
    if (listNode == NULL)
    {
        return 0;
    }

    // Check if it is both the head and the tail (only node in the list)
    else if (get_size_of_list() == 1)
    {
        head = NULL;
        tail = NULL;
        free(listNode);
        return 0;
    }

    // Check if this node is the head, and set the one behind it to the head after updating links
    else if ((listNode == head) && (listNode != tail))
    {
        // Set the node behind this one to be NULL
        listNode->prev->next = NULL;
        head = listNode->prev;
        free(listNode);
        return 0;
    }

    // Check if this node is the tail, and set the one behind it to the head after updating links
    else if ((listNode != head) && (listNode == tail))
    {
        listNode->next->prev = NULL;
        tail = listNode->next;
        free(listNode);
        return 0;
    }

    // It must be in the middle if we reached here
    // Set the node behind this node's 'next node' to be the deleting node's 'next node'
    // [a] <-> [b] <-> [c]   --> delete b -->  [a] <-> [c]     
    listNode->prev->next = listNode->next;
    // Same thing as above, but for the other direction
    listNode->next->prev = listNode->prev;

    // Free and return
    free(listNode);
    return 0;
}