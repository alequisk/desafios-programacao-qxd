class Solution {
public:
  int pivotIndex(vector<int>& nums) {
    int sz = nums.size();  
    vector<int> psa(sz, 0);
    for (int i = 0; i < sz; ++i) {
      if (i)
        psa[i] = psa[i - 1] + nums[i];
      else psa[i] = nums[i];
    }
    
    for (int i = 0; i < sz; ++i) {
      if (i == 0) {
        if (0 == psa[sz - 1] - psa[i]) return i;  
      } else {
        if (psa[i - 1] == psa[sz - 1] - psa[i]) return i;  
      }
      
    }
    return -1;
  }
};