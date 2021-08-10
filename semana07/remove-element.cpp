class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      int k = 0, sz = nums.size();
      for (int &x: nums) {
        if (x == val) {
          swap(x, nums[k++]);
        }
      }
      reverse(nums.begin(), nums.end());
      k = sz - k;
      return k;
    }
};