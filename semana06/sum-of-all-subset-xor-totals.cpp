class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
       int answer = solve(nums, 0, 0);
      return answer;
    }
  
    int solve(vector<int>& nums, int index, int xo) {
      if (index == nums.size()) {
        return xo;
      }
      int sum = nums[index];
      return solve(nums, index + 1, sum ^ xo) + solve(nums, index + 1, xo);
    }
};