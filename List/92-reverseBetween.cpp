struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 private:
  void reverseLinkList(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* cur = head;
    while (cur != nullptr) {
      ListNode* next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
  }

 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    // 增加头节点，可能避免一些分类讨论
    ListNode* dummyNode = new ListNode(0, head);
    ListNode* pre = dummyNode;
    // 找出反转范围最左边的结点
    for (int i = 0; i < left - 1; i++) {
      pre = pre->next;
    }
    // 找出反转范围最右边的结点
    ListNode* rightNode = pre;
    for (int i = 0; i < right - left + 1; i++) {
      rightNode = rightNode->next;
    }
    ListNode* leftNode = pre->next;
    ListNode* curr = rightNode->next;
    // 切出要反转的子链表
    pre->next = nullptr;
    rightNode->next = nullptr;
    // 反转
    reverseLinkList(leftNode);
    // 链接回原来的节点
    pre->next = rightNode;
    leftNode->next = curr;
    return dummyNode->next;
  }
};