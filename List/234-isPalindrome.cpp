#include <bits/stdc++.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  bool isPalindrome(ListNode *head) {
    std::stack<int> stk;
    ListNode *cur = head;
    while (cur != nullptr) {
      stk.push(cur->val);
      cur = cur->next;
    }

    cur = head;
    while (!stk.empty() && cur != nullptr) {
      int other = stk.top();
      if (other != cur->val) {
        return false;
      }
      stk.pop();
      cur = cur->next;
    }
    return true;
  }
};

int main() {
  ListNode *head = new ListNode(1);
  ListNode *cur = head;
  cur->next = new ListNode(2);
  cur = cur->next;
  cur->next = new ListNode(2);
  cur = cur->next;
  cur->next = new ListNode(1);
  cur = cur->next;

  std::cout << std::boolalpha
            << std::shared_ptr<Solution>()->isPalindrome(head);

  return 0;
}