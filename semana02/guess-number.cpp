/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
 
 /**
 * Link: https://leetcode.com/problems/guess-number-higher-or-lower/
 * Status: AC | 0ms | 5.7MB
 * */



class Solution {
public:
    int guessNumber(int n) {
      int low = 0, high = n;
      while (high > low + 1) {
        int mid = low + (high - low) / 2;
        int ret = guess(mid);
        if (ret == 0) return mid;
        if (ret > 0) {
          low = mid;
        } else {
          high = mid;
        }
      }
      return high;
    }
};
