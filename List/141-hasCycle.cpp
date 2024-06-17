#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return false;
    }
    ListNode *slow, *fast;
    slow = head, fast = head->next;
    while (fast != nullptr && fast->next != nullptr && slow != fast) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow == fast;
  }
};