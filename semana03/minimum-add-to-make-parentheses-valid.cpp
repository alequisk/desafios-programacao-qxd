/**
 * Solution by: Alex Sousa Cruz
 * Problem link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid
 */
class Solution {
public:
  int minAddToMakeValid(string s) {
    int l = 0, ans = 0;
    for (int c: s) {
      if (c == ')' && !l) {
        ++ans;
      } else if (c == ')' && l) {
        --l;
      } else if (c == '(') {
        ++l;
      }
    }
    ans += l;
    return ans;
  }
};