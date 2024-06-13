#include <bits/stdc++.h>

class Solution {
 public:
  // 只需要分别按顺序查找s中字符是否在t中按同样的顺序即可
  // 注意：s为空时是任何串的子串
  bool isSubsequence(std::string s, std::string t) {
    if (s == "") return true;
    const int& n1 = s.size();
    const int& n2 = t.size();
    int left = 0;
    for (int pos = 0; pos < n2; pos++) {
      if (s[left] == t[pos]) {
        left++;
      }
      if (left >= n1) {
        return true;
      }
    }

    return false;
  }
};