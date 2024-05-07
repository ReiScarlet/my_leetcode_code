#include <bits/stdc++.h>

class Solution {
 public:
  int maxProfit(std::vector<int>& prices) {
    int n = prices.size();
    int cost = INT_MAX, profit = 0;
    int result = 0;
    for (int i = 0; i < n; i++) {
      cost = std::min(cost, prices[i]);
      profit = std::max(profit, prices[i] - cost);
      std::printf(
          "profit[%d] cost[%d] result[%d] prices[%d]=%d prices[%d]=%d\n",
          profit, cost, result, i, prices[i], i - 1, prices[i - 1]);
      if (i > 0 && prices[i] < prices[i - 1]) {
        result += profit;
        profit = 0;
        cost = prices[i];
      }
    }
    result += profit;
    return result;
  }
};

int main() {
  auto pSolution = std::make_shared<Solution>();
  std::vector<int> vec{7, 1, 5, 3, 6, 4};
  std::cout << pSolution->maxProfit(vec) << "\n";
  std::cout << "\n\n";
  vec = {1, 2, 3, 4, 5};
  std::cout << pSolution->maxProfit(vec) << "\n";
  return 0;
}