#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int removeElement(vector<int>& nums, int val)
  {
    const int& n = nums.size();
    int left = 0;
    for (int right = 0; right < n; right++) {
      if (nums[right] != val) {
        nums[left] = nums[right];
        left++;
      }
    }
    return left;
  }
};