/*
------------------------------------------------
Problem: Palindrome Linked List
LeetCode: #234
Pattern: Fast & Slow Pointers + Linked List
Difficulty: Easy

Description:
Given the head of a singly linked list, return true if it
is a palindrome.

A palindrome reads the same forward and backward.

Example:

1 -> 2 -> 2 -> 1

Output:
true

Time Complexity: O(n)
Space Complexity: O(1)

Author: Fahima Azizi
------------------------------------------------
*/

class Solution {
public:

    ListNode* reverse(ListNode* head) {

        ListNode* previous = nullptr;

        while (head != nullptr) {

            ListNode* nextNode = head->next;

            head->next = previous;

            previous = head;
            head = nextNode;
        }

        return previous;
    }


    bool isPalindrome(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        // Find the middle of the linked list.
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half.
        ListNode* secondHalf = reverse(slow);

        ListNode* firstHalf = head;

        // Compare both halves.
        while (secondHalf != nullptr) {

            if (firstHalf->val != secondHalf->val) {
                return false;
            }

            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }
};