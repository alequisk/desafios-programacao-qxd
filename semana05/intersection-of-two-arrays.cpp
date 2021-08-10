class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        map<int, int> mp;
        set<int> s(nums1.begin(), nums1.end());
        set<int> t(nums2.begin(), nums2.end());
        for (int x: s) {
          mp[x]++;
        }
        for (int x: t) {
          if (mp[x]) res.push_back(x);
        }
      return res;
    }
};