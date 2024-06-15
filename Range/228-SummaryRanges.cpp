#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> summaryRanges(vector<int> &nums) {
    vector<string> answers;
    const int n = nums.size();
    int i = 0;
    while (i < n) {
      int start = i;
      while (i + 1 < n && nums[i] + 1 == nums[i + 1]) {
        i++;
      }
      if (start == i) {
        answers.push_back(to_string(nums[start]));
      } else {
        answers.push_back(to_string(nums[start]) + "->" + to_string(nums[i]));
      }
      i++;
    }
    return answers;
  }
};