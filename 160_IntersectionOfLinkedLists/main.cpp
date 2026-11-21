struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    unsigned int getLinkedListLength(ListNode *head) {
        ListNode* ptr = head;
        unsigned int len = 0;
        while (ptr != nullptr) {
            len++;
            ptr = ptr->next;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Length calculation
        unsigned int lenA = getLinkedListLength(headA);
        unsigned int lenB = getLinkedListLength(headB);

        // Pointers for both lists
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;

        // Equalize the difference from the intersection point of lists.
        // This will align the linked lists to have an intersection at
        // the same index.
        while (lenA > lenB && ptrA != nullptr) {
            ptrA = ptrA->next;
            lenA--;
        }
        while (lenB > lenA && ptrB != nullptr) {
            ptrB = ptrB->next;
            lenB--;
        }

        // Run along the now aligned linked lists and check equality
        while (ptrA != nullptr && ptrB != nullptr) {
            if (ptrA == ptrB) return ptrA;
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }

        // No intersection
        return nullptr;
    }
};
