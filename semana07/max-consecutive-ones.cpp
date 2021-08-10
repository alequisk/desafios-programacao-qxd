class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      auto it = nums.begin();
      int answer = 0;
      
      int n = nums.size();
      
      for (int i = 0; i < n; ++i) {
        if (nums[i]) {
          int pos = i;
          while (pos + 1 < n && nums[pos + 1]) ++pos;
          answer = max(answer, pos - i + 1);
          i = pos;
        }
      }
      
      return answer;
    }
};