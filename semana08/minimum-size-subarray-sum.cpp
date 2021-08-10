#define ll long long

class Solution {
public:
  int minSubArrayLen(int target, vector<int>& nums) {
    long long sum = accumulate(nums.begin(), nums.end(), 0LL);
    if (sum < target) return 0;
    int sz = nums.size();
    vector<ll> psa(sz + 1, 0LL);
    for (int i = 0; i < sz; ++i) {
      psa[i + 1] = nums[i] + psa[i];
    }
    
    int answer = sz;
    
    for (int i = 0; i < sz; ++i) {
      auto pos = lower_bound(psa.begin(), psa.end(), target + psa[i]);
      if (pos != psa.end()) {
        int mn = (pos - (psa.begin() + i));
        if (mn < answer)
          answer = mn;
      }
    }
    return answer;
  }
};