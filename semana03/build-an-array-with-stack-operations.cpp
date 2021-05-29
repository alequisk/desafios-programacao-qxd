/**
 * Solution by: Alex Sousa Cruz
 * Problem link: https://leetcode.com/problems/build-an-array-with-stack-operations/
 */
class Solution {
public:
  vector<string> buildArray(vector<int>& target, int n) {
    int idx = 0, nn = target.size();
    vector<string> ans;
    for (int i = 1; i <= n && idx < nn; ++i) {
      ans.push_back("Push");
      if (target[idx] == i) {
        idx++;
      } else {
        ans.push_back("Pop");
      }
    }
    return ans;
  }
};