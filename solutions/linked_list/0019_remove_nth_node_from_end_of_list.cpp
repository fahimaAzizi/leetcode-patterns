/*
------------------------------------------------
Problem: Remove Nth Node From End of List
LeetCode: #19
Pattern: Two Pointers + Linked List
Difficulty: Medium

Description:
Given the head of a linked list, remove the nth node
from the end of the list and return its head.

Example:

Input:
1 -> 2 -> 3 -> 4 -> 5
n = 2

Output:
1 -> 2 -> 3 -> 5

Time Complexity: O(n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Dummy node helps when removing the first node.
        ListNode dummy(0);
        dummy.next = head;

        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // Move fast pointer n + 1 steps ahead.
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end.
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node from the end.
        slow->next = slow->next->next;

        return dummy.next;
    }
};