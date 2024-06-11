#include <algorithm>
#include <map>
#include <random>
#include <vector>

class RandomizedSet {
 public:
  RandomizedSet() { srand((unsigned int)time(NULL)); }

  // 存储时把存储位置记录下，用于后续删除时使用
  bool insert(int val) {
    auto iter = records.find(val);
    if (iter != records.end()) {
      return false;
    }
    nums.push_back(val);
    records[val] = nums.size() - 1;
    return true;
  }

  // 选择从nums的最后一个元素与要删除的元素交换
  bool remove(int val) {
    auto iter = records.find(val);
    if (iter == records.end()) {
      return false;
    }
    records[nums.back()] = records[val];
    std::swap(nums[records[val]], nums[nums.size() - 1]);
    nums.pop_back();
    records.erase(val);
    return true;
  }

  int getRandom() { return nums[(int)rand() % nums.size()]; }

 private:
  std::vector<int> nums;
  std::map<int, int> records;  // 存储val插入的位置
};