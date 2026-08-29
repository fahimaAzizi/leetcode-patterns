/*
------------------------------------------------
Problem: Linked List Cycle
LeetCode: #141
Pattern: Fast & Slow Pointers
Difficulty: Easy

Description:
Given the head of a linked list, determine whether the
linked list contains a cycle.

A cycle happens when a node points back to a previous node.

Example:
1 -> 2 -> 3 -> 4
     ^         |
     |_________|

Output: true

Time Complexity: O(n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};