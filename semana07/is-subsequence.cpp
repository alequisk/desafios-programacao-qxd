class Solution {
public:
    bool isSubsequence(string s, string t) {
      int index = 0;
      int sza = s.size(), szb = t.size();
      if (sza == szb && sza == 0) return true;
      
      for(char c: t) {
        if (c == s[index]) {
          ++index;
        }
        if (sza == index) {
          return true;
        }
      }
      return false;
    }
};