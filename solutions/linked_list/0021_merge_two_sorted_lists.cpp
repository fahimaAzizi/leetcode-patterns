/*
------------------------------------------------
Problem: Merge Two Sorted Lists
LeetCode: #21
Pattern: Linked List
Difficulty: Easy

Description:
You are given the heads of two sorted linked lists.

Merge the two lists into one sorted linked list and return
its head.

Example:

list1 = 1 -> 2 -> 4
list2 = 1 -> 3 -> 4

Output:

1 -> 1 -> 2 -> 3 -> 4 -> 4

Time Complexity: O(n + m)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Create a dummy node to help build the new list.
        ListNode dummy(0);

        ListNode* current = &dummy;

        // Compare nodes from both lists.
        while (list1 != nullptr && list2 != nullptr) {

            if (list1->val <= list2->val) {

                current->next = list1;
                list1 = list1->next;

            } else {

                current->next = list2;
                list2 = list2->next;
            }

            current = current->next;
        }

        // Add the remaining nodes.
        if (list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }

        return dummy.next;
    }
};