class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
      std::sort(boxTypes.begin(), boxTypes.end(),
        [](vector<int> _a, vector<int> _b) -> bool {
          return _a[1] > _b[1];
        }
      );
      int ans = 0;
      for (auto v: boxTypes) {
        if (truckSize > 0) {
          int r = min(truckSize, v[0]);
          ans += r * v[1];
          truckSize -= r;
        }
      }
      return ans;
    }
};
