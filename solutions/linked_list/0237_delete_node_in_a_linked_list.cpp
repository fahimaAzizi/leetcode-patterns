/*
------------------------------------------------
Problem: Delete Node in a Linked List
LeetCode: #237
Pattern: Linked List
Difficulty: Medium

Description:
Given a node in a singly linked list, delete that node.

You are NOT given access to the head of the list.

Example:

Input:
4 -> 5 -> 1 -> 9

Delete node:
5

Output:
4 -> 1 -> 9

Time Complexity: O(1)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

class Solution {
public:
    void deleteNode(ListNode* node) {

        // Copy the next node's value into the current node.
        node->val = node->next->val;

        // Skip the next node.
        node->next = node->next->next;
    }
};