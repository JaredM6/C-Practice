#include <stdio.h>
#include "linked_list.h"

int test_suite();


int main()
{
    if (test_suite() == 0)
    {
        printf("All tests pass!\n");
        return 0;
    }
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

    // Check that the size is 1 after adding
    if (get_size_of_list() != 1)
    {
        printf("Size of list not 1!\n");
        return -1; 
    } printf("Get size 1 pass!\n");

    return 0;
}