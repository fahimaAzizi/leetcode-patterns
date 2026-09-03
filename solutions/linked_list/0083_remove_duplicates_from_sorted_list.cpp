/*
------------------------------------------------
Problem: Remove Duplicates from Sorted List
LeetCode: #83
Pattern: Linked List
Difficulty: Easy

Description:
Given the head of a sorted linked list, delete all
duplicates so that each element appears only once.

Example:

Input:
1 -> 1 -> 2 -> 3 -> 3

Output:
1 -> 2 -> 3

Time Complexity: O(n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* current = head;

        while (current != nullptr && current->next != nullptr) {

            // If the current value and next value are the same,
            // remove the duplicate node.
            if (current->val == current->next->val) {

                current->next = current->next->next;

            } else {

                // Move to the next node.
                current = current->next;
            }
        }

        return head;
    }
};