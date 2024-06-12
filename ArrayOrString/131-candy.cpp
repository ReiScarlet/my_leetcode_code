#include <bits/stdc++.h>

class Solution {
 public:
  // 相邻两个孩子评分更高的孩子会获得更多的糖果
  // 拆成两句话就是
  // 1.右边比左边评分高就会获得更多的糖果
  // 2.左边比右边评分高同理
  // 所以，只需要两边各处理一下就行了
  int candy(std::vector<int>& ratings) {
    const int n = ratings.size();
    std::vector<int> left(n);
    for (int i = 0; i < n; ++i) {
      if (i > 0 && ratings[i] > ratings[i - 1]) {
        left[i] = left[i - 1] + 1;
      } else {
        left[i] = 1;
      }
    }

    int right = 0, ret = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (i < n - 1 && ratings[i] > ratings[i + 1]) {
        right++;
      } else {
        right = 1;
      }
      ret += std::max(left[i], right);
    }
    return ret;
  }
};