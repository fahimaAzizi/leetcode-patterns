class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr)
            return head;

        Node* current = head;

        while (current != nullptr) {
            if (current->child != nullptr) {

                Node* nextNode = current->next;
                Node* childList = current->child;

                // Put child list after current node
                current->next = childList;
                childList->prev = current;

                current->child = nullptr;

                // Find the end of the child list
                Node* tail = childList;

                while (tail->next != nullptr)
                    tail = tail->next;

                // Connect child list to original next
                tail->next = nextNode;

                if (nextNode != nullptr)
                    nextNode->prev = tail;
            }

            current = current->next;
        }

        return head;
    }
};