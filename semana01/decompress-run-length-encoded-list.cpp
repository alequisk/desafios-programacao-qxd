/**
 * Link: https://leetcode.com/problems/decompress-run-length-encoded-list/
 * Status: AC | 8ms | 10.1MB
 * */
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
      vector<int> ans; int n = nums.size();
      for (int i = 0; i < n; i+=2) {
        for (int j = 0; j < nums[i]; ++j)
          ans.push_back(nums[i + 1]);
      }
      
      return ans;
    }
};
