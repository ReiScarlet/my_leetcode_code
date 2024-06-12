#include <bits/stdc++.h>

class Solution {
 public:
  bool isPalindrome(std::string s) {
    std::string str;
    for (const char& ch : s) {
      if (std::isalnum(ch)) {
        str += std::tolower(ch);
      }
    }
    int left = 0, right = str.size() - 1;
    while (left < right) {
      if (str[left] != str[right]) return false;
      left++;
      right--;
    }
    return true;
  }
};

int main() {
  std::cout << std::boolalpha
                 << std::make_shared<Solution>()->isPalindrome(
                        "A man, a plan, a canal: Panama");
  return 0;
}