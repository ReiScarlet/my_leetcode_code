#include <bits/stdc++.h>

class Solution {
 public:
  std::vector<int> productExceptSelf(std::vector<int>& nums) {
    const int length = nums.size();
    std::vector<int> prefix(length, 0), suffix(length, 0), ans(length, 0);
    prefix[0] = 1;
    for (int i = 1; i < length; i++) {
      prefix[i] = nums[i - 1] * prefix[i - 1];
    }
    suffix[length - 1] = 1;
    for (int i = length - 2; i >= 0; i--) {
      suffix[i] = nums[i + 1] * suffix[i + 1];
    }
    for (int i = 0; i < length; i++) {
      ans[i] = prefix[i] * suffix[i];
    }
    return ans;
  }
};