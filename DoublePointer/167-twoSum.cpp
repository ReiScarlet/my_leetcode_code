#include <bits/stdc++.h>

class Solution {
 public:
  std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    while (left < right) {
      int myTarget = numbers[left] + numbers[right];
      if (myTarget < target) {
        left++;
      } else if (myTarget > target) {
        right--;
      } else {
        return {left + 1, right + 1};
      }
    }
    return {};
  }
};