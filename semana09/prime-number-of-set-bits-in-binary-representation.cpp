class Solution {
public:
    int countPrimeSetBits(int left, int right) {
      int answer = 0;
      for (int i = left; i <= right; ++i) {
        int sz = __builtin_popcount(i);
        int t = 0; if (sz == 1) continue;
        for (int j = 2; j * j <= sz; ++j) {
          if (sz % j == 0) {++t; break;}
        }
        if (t == 0) ++answer;
      }
      return answer;
    }
};