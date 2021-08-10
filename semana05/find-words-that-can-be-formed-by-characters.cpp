class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
      int ans = 0;
      map<char, int> mp;
      for (char c: chars) mp[c]++;
      for (string s: words) {
        map<char, int> m;
        for (char c: s) {
          m[c]++;
        }
        int ok = true;
        for (auto [index, value]: m) {
          if (mp[index] < value) ok = false;
        }
        if (ok) ans += s.size();
      }
      return ans;
    }
};