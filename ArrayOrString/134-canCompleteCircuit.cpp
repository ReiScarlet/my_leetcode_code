#include <bits/stdc++.h>

class Solution {
 public:
  // 要想得到出发点，只需要画出到达下一点的剩余油量，然后找出最小值所在的点
  // 从该点按顺序出发，直到回到起点，其剩余油量一定大于等于0
  // 可以画个图，以最小值所在的点做y=0的轴就理解了
  //
  // 其次，总可加油油量要大于等于路程耗油量，否则路程无法完成
  int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
    int length = gas.size();
    int sum = 0;
    int minSum = INT32_MAX, minSumIndex = 0;
    for (int i = 0; i < length; i++) {
      sum += gas[i] - cost[i];
      if (sum < minSum) {
        minSum = sum;
        minSumIndex = i;
      }
    }
    if (sum < 0) {
      return -1;
    } else if (minSum >= 0) {
      return 0;
    } else {
      // 偏移一位是因为从出发点是从0计算，而剩余油量是从1开始
      return (minSumIndex + 1) % length;
    }
  }
};