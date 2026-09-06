class Solution {
public:

    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* current = &dummy;

        while (a != nullptr && b != nullptr) {
            if (a->val <= b->val) {
                current->next = a;
                a = a->next;
            } else {
                current->next = b;
                b = b->next;
            }

            current = current->next;
        }

        if (a != nullptr)
            current->next = a;
        else
            current->next = b;

        return dummy.next;
    }

    ListNode* mergeLists(vector<ListNode*>& lists, int left, int right) {
        if (left > right)
            return nullptr;

        if (left == right)
            return lists[left];

        int mid = left + (right - left) / 2;

        ListNode* first = mergeLists(lists, left, mid);
        ListNode* second = mergeLists(lists, mid + 1, right);

        return mergeTwoLists(first, second);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;

        return mergeLists(lists, 0, lists.size() - 1);
    }
};