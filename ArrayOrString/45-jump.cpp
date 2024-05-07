#include <bits/stdc++.h>

class Solution {
 public:
  int jump(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> dp(n, 10000);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[j] >= (i - j)) {
        //   std::printf("dp[%d]=%d dp[%d]=%d\n", i, dp[i], j, dp[j]);
          dp[i] = std::min(dp[j] + 1, dp[i]);
        }
      }
    }
    return dp.back();
  }
};

int main() {
  std::vector<int> vec{2, 3, 1, 1, 4};
  std::cout << std::make_shared<Solution>()->jump(vec) << "\n";
  return 0;
}