/**
 * Solution by: Alex Sousa Cruz
 * Problem link: https://leetcode.com/problems/baseball-game/
 */
class Solution {
public:
  int calPoints(vector<string>& ops) {
    vector<int> stack;
    int pointer = 0;
    for (string s: ops) {
      if (s == "+") {
        stack.push_back(stack[pointer - 1] + stack[pointer - 2]);
        pointer++;
      } else if (s == "D") {
        stack.push_back(stack[pointer - 1] * 2);
        pointer++;
      } else if (s == "C") {
        stack.pop_back();
        pointer--;
      } else {
        int value = 0;
        for (char c: s) {
          if (c == '-') continue;
          value *= 10; value += c - '0';
        } if (s[0] == '-') value = -value;
        stack.push_back(value);
        pointer++;
      }
    }
    int ans = 0;
    for (int x: stack) {
      ans += x;
    }
    return ans;
  }
};