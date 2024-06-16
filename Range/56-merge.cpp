#include <bits/stdc++.h>

class Solution {
 public:
  std::vector<std::vector<int>> merge(
      std::vector<std::vector<int>>& intervals) {
    if (intervals.size() == 0) {
      return {};
    }
    std::sort(intervals.begin(), intervals.end());
    std::vector<std::vector<int>> merged;
    const int n = intervals.size();
    for (int i = 0; i < n; ++i) {
      int L = intervals[i][0], R = intervals[i][1];
      if (!merged.size() || merged.back()[1] < L) {  // new array
        merged.push_back({L, R});
      } else {  // interval
        merged.back()[1] = std::max(merged.back()[1], R);
      }
    }
    return merged;
  }
};