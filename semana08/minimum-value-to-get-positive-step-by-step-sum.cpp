class Solution {
public:
  int minStartValue(vector<int>& nums) {
    int mn = 0;
    int sum = 0;
    for (int x: nums) {
      sum += x;
      if (sum < 0) mn = min(sum, mn);
    }
    return -mn + 1;
  }
};