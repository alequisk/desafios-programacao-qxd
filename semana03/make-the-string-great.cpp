/**
 * Solution by: Alex Sousa Cruz
 * Problem link: https://leetcode.com/problems/make-the-string-great/
 */
class Solution {
public:
  string makeGood(string s) {
    vector<char> stack;
    int pointer = 0;
    for (char c: s) {
      stack.push_back(c);
      ++pointer; bool uncheck = true;
      while (stack.size() > 1 && uncheck) {
        if (stack[pointer - 1] != stack[pointer - 2]
            && tolower(stack[pointer - 1]) == tolower(stack[pointer - 2])) {
          pointer -= 2;
          stack.pop_back();
          stack.pop_back();
        } else uncheck = false;
      }
    }
    string ans = "";
    for (char c: stack) {
      ans += c;
    }
    return ans;
  }
};