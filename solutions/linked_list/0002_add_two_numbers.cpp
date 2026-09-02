/*
------------------------------------------------
Problem: Add Two Numbers
LeetCode: #2
Pattern: Linked List + Math
Difficulty: Medium

Description:
You are given two non-empty linked lists representing
two non-negative integers.

The digits are stored in reverse order.

Add the two numbers and return the result as a linked list.

Example:

l1 = 2 -> 4 -> 3
l2 = 5 -> 6 -> 4

This represents:

342 + 465 = 807

Output:

7 -> 0 -> 8

Time Complexity: O(max(n, m))
Space Complexity: O(max(n, m))

Author: Fahima Azizi
------------------------------------------------
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode dummy(0);
        ListNode* current = &dummy;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {

            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;

            current->next = new ListNode(sum % 10);

            current = current->next;
        }

        return dummy.next;
    }
};