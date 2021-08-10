class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
      map<int, int> mp;
      for (int x: arr) {
        mp[x]++;
      }
      set<int> s;
      for (auto [index, value]: mp) {
        s.insert(value);
      }
      return s.size() == mp.size();
    }
};