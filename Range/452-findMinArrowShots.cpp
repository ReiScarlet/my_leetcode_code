#include <bits/stdc++.h>

class Solution {
 public:
  int findMinArrowShots(std::vector<std::vector<int>>& points) {
    std::sort(points.begin(), points.end());
    std::vector<std::vector<int>> ans;
    ans.push_back(points[0]);
    const int n = points.size();
    for (int i = 1; i < n; i++) {
      if (points[i][0] <= ans.back()[1]) {
        ans.back()[0] = std::max(ans.back()[0], points[i][0]);
        ans.back()[1] = std::min(ans.back()[1], points[i][1]);
      } else {
        ans.push_back(points[i]);
      }
    }
    return ans.size();
  }
};