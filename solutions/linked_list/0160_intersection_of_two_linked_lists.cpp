/*
------------------------------------------------
Problem: Intersection of Two Linked Lists
LeetCode: #160
Pattern: Linked List + Two Pointers
Difficulty: Easy

Description:
Given the heads of two singly linked lists, return the node
where the two linked lists intersect.

If the two linked lists do not intersect, return nullptr.

Example:

List A:
4 -> 1
       \
        8 -> 4 -> 5
       /
5 -> 6 -> 1

List B:

The intersection node is 8.

Time Complexity: O(n + m)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* pointerA = headA;
        ListNode* pointerB = headB;

        while (pointerA != pointerB) {

            // When pointerA reaches the end,
            // move it to the beginning of List B.
            if (pointerA == nullptr) {
                pointerA = headB;
            } else {
                pointerA = pointerA->next;
            }

            // When pointerB reaches the end,
            // move it to the beginning of List A.
            if (pointerB == nullptr) {
                pointerB = headA;
            } else {
                pointerB = pointerB->next;
            }
        }

        return pointerA;
    }
};