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
};