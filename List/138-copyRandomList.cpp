#include <bits/stdc++.h>

#include <cstddef>

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
 private:
  // 构建每个node对应复制出来的新node的映射
  std::unordered_map<Node*, Node*> nodeMap;

 public:
  // 先创建出所有的node
  // 然后在将next和random链接起来
  Node* copyRandomList(Node* head) {
    if (!head) {
      return NULL;
    }
    if (!nodeMap.count(head)) {
      Node* newHead = new Node(head->val);
      nodeMap[head] = newHead;
      newHead->next = copyRandomList(head->next);
      newHead->random = copyRandomList(head->random);
    }
    return nodeMap[head];
  }
};