#include <bits/stdc++.h>

class Solution {
 public:
  // 仅需要维护一个当前能到达的下标
  // 如果途中有一个下标无法到达，直接返回false
  bool canJump(std::vector<int>& nums) {
    int k = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (i > k) return false;
      k = std::max(k, i + nums[i]);
    }
    return true;
  }
};

int main() {
  std::vector<int> vec{2, 0, 0};
  auto pSolution = std::make_shared<Solution>();
  std::cout << std::boolalpha << pSolution->canJump(vec);
  return 0;
}