class Solution {
public:
    string reverseVowels(string s) {
      vector<int> indexes;
      int idx = 0;
      for (char c: s) {
        if (isVowel(c)) {
          indexes.push_back(idx);
        }
        ++idx;
      }
      int sz = indexes.size();
      for (int i = 0; i < sz / 2; ++i) {
        swap(s[indexes[i]], s[indexes[sz - i - 1]]);
      }
      return s;
    }
    
    bool isVowel(char c) {
      c = tolower(c);
      return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};