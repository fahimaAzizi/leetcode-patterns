/*
------------------------------------------------
Problem: Rotate List
LeetCode: #61
Pattern: Linked List
Difficulty: Medium

Description:
Given the head of a linked list, rotate the list to the
right by k places.

Example:

Input:
1 -> 2 -> 3 -> 4 -> 5
k = 2

Output:
4 -> 5 -> 1 -> 2 -> 3

Time Complexity: O(n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        // If the list is empty or has one node.
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        // Find the length and last node.
        int length = 1;
        ListNode* tail = head;

        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }

        // Reduce unnecessary rotations.
        k = k % length;

        if (k == 0) {
            return head;
        }

        // Make the list circular.
        tail->next = head;

        // Find the new tail.
        int stepsToNewTail = length - k;

        ListNode* newTail = head;

        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        // The next node becomes the new head.
        ListNode* newHead = newTail->next;

        // Break the circle.
        newTail->next = nullptr;

        return newHead;
    }
};