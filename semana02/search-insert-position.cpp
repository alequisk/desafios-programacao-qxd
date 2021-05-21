/**
* Link: https://leetcode.com/problems/search-insert-position/
* Status: AC | 0ms | 9.7MB
* */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      return upper_bound(nums.begin(), nums.end(), target - 1) - nums.begin();
    }
};
