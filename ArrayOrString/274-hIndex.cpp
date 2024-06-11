#include <bits/stdc++.h>

class Solution {
 public:
  // 对citation进行排序后，对于每个元素，都有大于等于citation[i]的值有citations.size()-i个
  // 由于h指数是找出，大于等于h的值至少有h个，则h值应为citations[i]与citations.size()-i之间的最小值
  // 再有题目直接对所有找出的h指数筛选最大值即可
  //
  // 举个例子，如果我有100个1组成的序列，那么h指数的值为1，因为大于等于1的值至少有1个
  // 反之，有1个100的序列，其h指数也为1
  int hIndex(std::vector<int>& citations) {
    std::sort(citations.begin(), citations.end());
    int ans = 0;
    const int length = citations.size();
    for (int i = 0; i < length; i++) {
      ans = std::max(ans, std::min(citations[i], length - i));
    }
    return ans;
  }
};