class Solution {
public:
    vector<int> minSubsequence(vector<int>& a) {
      int s = 0;
      int sum = accumulate(a.begin(), a.end(), 0);
      sort(a.begin(), a.end(), greater<int>());
      vector<int> ret;
      for (int x: a) {
        ret.push_back(x);
        s += x;
        sum -= x;
        if (s > sum) break;
      }
      return ret;
    }
};
