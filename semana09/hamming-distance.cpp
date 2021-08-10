class Solution {
public:
  int hammingDistance(int x, int y) {
    int answer = x ^ y;
    return __builtin_popcount(answer);
  }
};