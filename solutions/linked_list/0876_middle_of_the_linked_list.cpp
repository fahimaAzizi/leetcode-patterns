/*
------------------------------------------------
Problem: Middle of the Linked List
LeetCode: #876
Pattern: Fast & Slow Pointers
Difficulty: Easy

Description:
Given the head of a singly linked list, return the middle
node of the linked list.

If there are two middle nodes, return the second middle node.

Example:
Input:
1 -> 2 -> 3 -> 4 -> 5

Output:
3

Time Complexity: O(n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};