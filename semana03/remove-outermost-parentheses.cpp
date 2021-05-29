/**
 * Solution by: Alex Sousa Cruz
 * Problem link: https://leetcode.com/problems/remove-outermost-parentheses/
 */
class Solution {
public:
  string removeOuterParentheses(string s) {
    int n = s.length();
    vector<char> stack;
    string ans = "";
    int bg = 0;
    for (int i = 0; i < n; ++i) {
      if (stack.empty()) { bg = i; }
      if (s[i] == ')') stack.pop_back();
      else stack.push_back('(');
      if (i > 0 && stack.empty()) {
        ans += s.substr(bg + 1, i - bg - 1);
      }
    }
    return ans;
  }
};