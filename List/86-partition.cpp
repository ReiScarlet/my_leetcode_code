struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    if (!head || !head->next) {
      return head;
    }
    ListNode* dummyNode = new ListNode(0, head);
    ListNode *prev = dummyNode, *cur = head;
    // 找到第一个大于x的节点，之前找到小于x的节点都插在这之前
    while (cur && cur->val < x) {
      prev = cur;
      cur = cur->next;
    }

    while (cur && cur->next) {
      if (cur->next->val < x) {
        // 去掉节点
        ListNode* insertNode = cur->next;
        cur->next = cur->next->next;
        // 移动到前面
        insertNode->next = prev->next;
        prev->next = insertNode;
        prev = prev->next;
      } else {
        cur = cur->next;
      }
    }
    return dummyNode->next;
  }
};