#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    vector<vector<int>> answer;
    int L = newInterval[0], R = newInterval[1];
    bool placed = false;
    for (const auto &interval : intervals) {
      if (interval[0] > R) {
        // newInterval在左侧时且无交集
        // 则代表右侧的都无交集
        if (!placed) {
          answer.push_back({L, R});
          placed = true;
        }
        answer.push_back(interval);
      } else if (interval[1] < L) {
        // 在右侧无交集，有可能与剩余的有交集
        answer.push_back(interval);
      } else {
        // 有交集时
        L = min(L, interval[0]);
        R = max(R, interval[1]);
      }
    }
    // 一直没有交集时,加上去
    if (!placed) {
      answer.push_back({L, R});
    }
    return answer;
  }
};