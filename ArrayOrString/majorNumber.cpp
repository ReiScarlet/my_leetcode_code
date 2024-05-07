#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int count = 0, result = -1;
    for (const int& num : nums) {
      if (num == result) {
        ++count;
      } else if ((--count) < 0) {
        result = num;
        count = 1;
      }
    }
    return result;
  }
};

int main() {
  auto pSoultion = std::make_shared<Solution>();
  std::vector<int> vec{};
  int n = 0;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int num = 0;
    std::cin >> num;
    vec.emplace_back(num);
  }
  std::cout << pSoultion->majorityElement(vec) << "\n";
  return 0;
}