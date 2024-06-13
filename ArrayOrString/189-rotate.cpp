#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void reverse(vector<int>& nums, int left, int right) {
    int mid = (right - left) / 2;
    for (int i = 0; i <= mid; i++) {
      std::swap(nums[left + i], nums[right - i]);
    }

    // std::cout << "left = " << left << " right = " << right << " ";
    // for (const int& num : nums) {
    //   std::cout << num << " ";
    // }
    // std::cout << std::endl;
  }

  void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;  // 优化，处理k很大的时候
    reverse(nums, 0, n - k - 1);
    reverse(nums, n - k, n - 1);
    reverse(nums, 0, n - 1);
  }
};

int main() {
  auto pSolution = std::make_shared<Solution>();
  vector<int> vec{1};
  pSolution->rotate(vec, 0);
  return 0;
}