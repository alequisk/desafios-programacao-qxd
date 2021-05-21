/**
 * Link: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
 * Status: AC | 4ms | 9.7MB
 * */
class Solution {
public:
    int findNumbers(vector<int>& nums) {
      int ans = 0;
      for (int x: nums) {
        int n = 1; x /= 10;
        while (x > 0) {
          x /= 10; ++n;
        }
        ans += !(n & 1);
      }
      
      return ans;
    }
};
