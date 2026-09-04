/*
------------------------------------------------
Problem: Odd Even Linked List
LeetCode: #328
Pattern: Linked List
Difficulty: Medium

Description:
Given the head of a singly linked list, group all nodes with
odd positions together, followed by nodes with even positions.

The first node is considered odd.
The second node is considered even.

Example:

Input:
1 -> 2 -> 3 -> 4 -> 5

Output:
1 -> 3 -> 5 -> 2 -> 4

Time Complexity: O(n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;

        // Save the beginning of the even list.
        ListNode* evenHead = even;

        while (even != nullptr && even->next != nullptr) {

            // Connect odd nodes together.
            odd->next = even->next;
            odd = odd->next;

            // Connect even nodes together.
            even->next = odd->next;
            even = even->next;
        }

        // Connect odd list with even list.
        odd->next = evenHead;

        return head;
    }
};