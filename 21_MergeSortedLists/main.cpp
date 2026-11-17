struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      // Node for building the output list
      ListNode ptrHead = ListNode(0);
      // Pointer for the output list node
      ListNode* ptr = &ptrHead;

      // Iterate, attaching the lower value of the two lists to the ptr, then
      // advancing the list and pointer.
      while (list1 && list2) {
        if (list1->val < list2->val) {
          ptr->next = list1;
          list1 = list1->next;
        } else {
          ptr->next = list2;
          list2 = list2->next;
        }

        ptr = ptr->next;
      }

      // Assign remaining values in either list to the end
      ptr->next = list1 ? list1 : list2;

      // First was dummy 0, return list from next node
      return ptrHead.next;
    }
};
