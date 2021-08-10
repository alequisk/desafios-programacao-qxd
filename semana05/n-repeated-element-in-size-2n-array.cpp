class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        map<int, int> mp;
        for (int x: nums) {
          mp[x]++;
        }
      
        for (auto [a, k]: mp) {
          if (k == nums.size()/2) return a;
        }
      return 0;
    }
};