class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
      pair<int, int> l[3];
      for (int i = 0; i < 3; ++i) {
        l[i].second = i;
      }
      
      l[0].first = a;
      l[1].first = b;
      l[2].first = c;
      string ans = "";
      int last = -1;
      while (true) {
        std::sort(l, l + 3);
        std::reverse(l, l + 3);
        if (l[0].first > 0) {
          if (l[0].second == last) {
            if (l[1].first > 0) {
              int rem = min(l[1].first, 1);
              l[1].first -= rem;  
              while (rem > 0) {
                rem--; ans += char('a' + l[1].second);
              }
              last = l[1].second;
            } else {
              break;
            }
          } else {
            int rem = min(l[0].first, 2);
            l[0].first -= rem;
            while (rem > 0) {
              rem--; ans += char('a' + l[0].second);
            }
            last = l[0].second;
          }
        } else break;
      }
      
      return ans;
    }
};
