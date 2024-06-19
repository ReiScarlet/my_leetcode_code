struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0) {
      return head;
    }
    int length = 1;
    ListNode* cur = head;
    while (cur->next != nullptr) {
      length++;
      cur = cur->next;
    }
    k = k % length;
    if (k == 0) {
      return head;
    }
    cur->next = head;
    for (int i = 0; i < length - k; i++) {
      cur = cur->next;
    }
    ListNode* newHead = cur->next;
    cur->next = nullptr;
    return newHead;
  }
};