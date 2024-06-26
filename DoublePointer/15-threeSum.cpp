#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> ans;
    std::sort(nums.begin(), nums.end());
    const int n = nums.size();
    for (int i = 0; i < n - 2; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      int left = i + 1, right = n - 1;
      while (left < right) {
        int sum = nums[left] + nums[right] + nums[i];
        if (sum == 0) {
          ans.push_back({nums[i], nums[left], nums[right]});
          while (left < right && nums[left] == nums[left + 1]) {
            ++left;
          }
          while (left < right && nums[right] == nums[right - 1]) {
            right--;
          }
          ++left;
          --right;
        } else if (sum < 0) {
          ++left;
        } else {
          --right;
        }
      }
    }
    return ans;
  }
};