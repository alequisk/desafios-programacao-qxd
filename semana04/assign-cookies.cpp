class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
      sort(g.begin(), g.end());
      sort(s.begin(), s.end());
      int j = 0, ans = 0, n = s.size();;
      for (int &c: g) {
        while (j < n && !(s[j] >= c)) {
          ++j;
        } 
        if (j < n && s[j] >= c) ++ans, ++j;
      }
      
      return ans;
    }
};
