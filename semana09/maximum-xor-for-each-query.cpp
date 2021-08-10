class Solution {
public:
  vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int mask = (1 << maximumBit) - 1;
    int xo = 0; vector<int> answer;
    for (int x: nums) {
      xo ^= x;
      answer.push_back(xo ^ mask);
    }
    reverse(answer.begin(), answer.end());
    return answer;
  }
};