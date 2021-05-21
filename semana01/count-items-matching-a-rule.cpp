/**
 * Link: https://leetcode.com/problems/count-items-matching-a-rule/
 * Status: AC | 80ms | 36.5MB
 * */
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
      int ans = 0;
      string rules[] = {"type", "color", "name"};
      for (auto arr: items) {
        int n = arr.size();
        bool ok = false;
        for (int i = 0; i < n; ++i) {
          if (arr[i] == ruleValue && rules[i % 3] == ruleKey) {
            ok = true; break;
          }
        }
        ans += ok == 1;
      }
      
      return ans;
    }
};
