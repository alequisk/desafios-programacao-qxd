class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      vector<vector<int>> answer;
      sort(nums.begin(), nums.end());
      do {
        answer.push_back(vector<int>());
        for (int x: nums) {
          answer.back().push_back(x);
        }
      } while (next_permutation(nums.begin(), nums.end()));
      return answer;
    }
};