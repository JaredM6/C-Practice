#include <stdio.h>
#include "linked_list.h"

int test_suite();


int main()
{
    if (test_suite() == 0)
    {
        printf("All tests PASS!\n");
        return 0;
    }
    printf("FAIL!\n");
    return -1;
}

int test_suite()
{
    // Node for testing
    ListNode* testNode;

    // Check that we can make a node
    testNode = make_new_node();
    if (testNode == NULL)
    {
        printf("Make new node failed!\n");
        return -1; 
    } printf("Made new node pass!\n");


    // Check that size is 0 (nothing added to list yet)
    if (get_size_of_list() != 0)
    {
        printf("Size was not 0!\n");
        return -1; 
    } printf("Get size 0 pass!\n");


    // Check that a node is added to list
    if (add_node(testNode) != 0)
    {
        printf("Add node test failed!\n");
        return -1;
    } printf("Add to list pass!\n");


    // LIST STATUS: [testNode]


    // Check that the size is 1 after adding
    if (get_size_of_list() != 1)
    {
        printf("Size of list not 1!\n");
        return -1; 
    } printf("Get size 1 pass!\n");


    // Check that a second node can be made
    ListNode* testNode2 = make_new_node();
    if (testNode2 == NULL)
    {
        printf("Make new node 2 failed!\n");
        return -1; 
    } printf("Made new node 2 pass!\n");


    // Check that size is NOT 2 (we have not added to list yet!)
    if (get_size_of_list() != 1)
    {
        printf("Size was not 1!\n");
        return -1; 
    } printf("Check not size 2 pass!\n");


    // Check that the second node is added to the list correctly
    if ((add_node(testNode2) != 0) && (testNode2->prev == testNode))
    {
        printf("Add node 2 test failed!\n");
        return -1;
    } printf("Add node 2 to list pass!\n");


    // LIST STATUS: [testNode] <-> [testNode2]


    // Check that the size is 2 after adding
    if (get_size_of_list() != 2)
    {
        printf("Size of list not 2!\n");
        return -1; 
    } printf("Get size 2 pass!\n");

    // Check that the first node created gets deleted successfully
    if (delete_node(testNode))
    {
        printf("Node not deleted!\n");
        return -1; 
    } printf("Deletion passed, confirming deletion...\n");

    // Check that the size of the list is 1 after deletion for confirmation
    if (get_size_of_list() != 1)
    {
        printf("Size of list not 1!\n");
        return -1; 
    } printf("Node deleted, size 1 check pass!\n");

    // Check that the remaining node is the only node and has only NULL connections
    if ((testNode2->next != NULL) && (testNode2->prev != NULL))
    {
        printf("Connections not NULL!\n");
        return -1; 
    } printf("Node has no connections (good)!\n");


    // LIST STATUS: [testNode2]


    // Check that we can delete the only node in the list
    // Check that the first node created gets deleted successfully
    if (delete_node(testNode2))
    {
        printf("Node not deleted!\n");
        return -1; 
    } printf("Deletion passed, confirming deletion...\n");

    // Check that the size of the list is 1 after deletion for confirmation
    if (get_size_of_list() != 0)
    {
        printf("Size of list not 0!\n");
        return -1; 
    } printf("Node deleted, size 0 check pass!\n");


    // LIST STATUS: (empty)

    
    return 0;
}