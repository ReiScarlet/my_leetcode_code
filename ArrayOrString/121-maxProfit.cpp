#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int cost = INT32_MAX, profit = 0;
    for (int price : prices) {
      cost = std::min(cost, price);
      profit = std::max(profit, price - cost);
    }
    return profit;
  }
};