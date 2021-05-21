/**
 * Link: https://leetcode.com/problems/find-smallest-letter-greater-than-target/
 * Status: AC | 8ms | 15.9MB
 * */
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
      sort(letters.begin(), letters.end());
      auto it = upper_bound(letters.begin(), letters.end(), target);
      if (it == letters.end())
        it = letters.begin();
      return *it;
    }
};
