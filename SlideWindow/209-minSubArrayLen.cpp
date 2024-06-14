#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int minLen = INT32_MAX;
    const int n = nums.size();
    if (n == 1) {
      return nums[0] == target ? 1 : 0;
    }
    int left = 0, tmpSum = 0;
    for (int right = 0; right < n; right++) {
      tmpSum += nums[right];
      while (left <= right && tmpSum >= target) {
        minLen = min(minLen, right - left + 1);
        tmpSum -= nums[left];
        left++;
      }
    }
    return minLen == INT32_MAX ? 0 : minLen;
  }
};