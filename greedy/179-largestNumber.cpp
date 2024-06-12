#include <bits/stdc++.h>

class Solution {
 public:
  static bool cmp(const int& a, const int& b) {
    std::string str_a = std::to_string(a);
    std::string str_b = std::to_string(b);
    return str_a + str_b > str_b + str_a;
  }

  std::string largestNumber(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end(), cmp);
    if (nums[0] == 0) {
      return "0";
    }
    std::string ret;
    for (const int& num : nums) {
      ret += std::to_string(num);
    }
    return ret;
  }
};