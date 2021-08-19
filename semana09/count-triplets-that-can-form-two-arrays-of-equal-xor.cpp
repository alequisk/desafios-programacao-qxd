class Solution {
public:
  int countTriplets(vector<int>& arr) {
    int sz = arr.size();
    vector<int> psa(sz + 1, 0);
    for (int i = 0; i < sz; ++i) {
      psa[i + 1] = psa[i] ^ arr[i];
    }
    int ans = 0;
    for (int i = 1; i <= sz - 1; ++i) {
      for (int j = i + 1; j <= sz; ++j) {
        for (int k = j; k <= sz; ++k) {
          if (psa[j - 1] ^ psa[i - 1] == psa[k] ^ psa[j - 1]) ++ans;
        }
      }
    }
    return ans;
  }
};