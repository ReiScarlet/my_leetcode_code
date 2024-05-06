#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int removeDuplicates(vector<int>& nums)
  {
    int lenght = 0;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] != nums[lenght]) {
        if (i - lenght > 1) {
          nums[lenght + 1] = nums[i];
        }
        lenght++;
      }
    }
    return lenght + 1;
  }

  // 题号: 80
  int removeDuplicates_II(vector<int>& nums)
  {
    // const int& n = nums.size();
    // if (n <= 2) {
    //   return n;
    // }

    // int slow = 2, fast = 2;
    // while (fast < n) {
    //   // std::printf("nums[%d-2]=%d nums[%d]=%d", slow, nums[slow - 2], fast,
    //   // nums[fast]);
    //   if (nums[slow - 2] != nums[fast]) {
    //     nums[slow] = nums[fast];
    //     ++slow;
    //   }
    //   ++fast;
    //   // std::printf(" slow[%d] fast[%d]\n", slow, fast);
    // }

    // return slow;

    return removeDulicatesTMP(nums, 2);
  }

  // 仅针对有序序列有效的模板
  // 原地删除重复出现的元素，使得出现次数超过两次的元素只出现k次
  int removeDulicatesTMP(vector<int>& nums, int k)
  {
    int len = 0;
    for (const int& num : nums) {
      if (len < k || nums[len - k] != num) {
        nums[len] = num;
        len++;
      }
    }
    return len;
  }
};

int
main()
{
  auto pSoulution = std::make_shared<Solution>();
  std::vector<int> nums{ 1, 1, 1, 2, 2, 3, 3 };
  pSoulution->removeDuplicates_II(nums);
  return 0;
}