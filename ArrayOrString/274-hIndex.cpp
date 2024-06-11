#include <bits/stdc++.h>

class Solution {
 public:
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