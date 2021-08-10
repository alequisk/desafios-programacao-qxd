class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int sz = nums.size();
      for (int i = 0; i < sz;) {
        if (nums[i] == 0) {
          int j = i;
          while (j + 1 < sz) {
            swap(nums[j], nums[j + 1]);
            ++j;
          }
          --sz;
        } else ++i;
      }
    }
};