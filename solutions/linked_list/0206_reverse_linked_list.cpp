/*
------------------------------------------------
Problem: Reverse Linked List
LeetCode: #206
Pattern: Linked List
Difficulty: Easy

Description:
Given the head of a singly linked list, reverse the list
and return the new head.

Example:
Input:
1 -> 2 -> 3 -> 4 -> 5

Output:
5 -> 4 -> 3 -> 2 -> 1

Time Complexity: O(n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* previous = nullptr;
        ListNode* current = head;

        while (current != nullptr) {

            // Save the next node.
            ListNode* nextNode = current->next;

            // Reverse the connection.
            current->next = previous;

            // Move previous forward.
            previous = current;

            // Move current forward.
            current = nextNode;
        }

        return previous;
    }
};