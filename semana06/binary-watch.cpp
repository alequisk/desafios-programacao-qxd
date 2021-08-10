class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
      vector<string> ans;
        for (int hours = 0; hours < (1<<4); ++hours) {
          if (hours > 11) break;
          for (int minutes = 0; minutes < (1 << 6); minutes++) {
            if (minutes > 59) break;
            int turnHours = __builtin_popcount(hours);
            int turnMinutes = __builtin_popcount(minutes);
            if (turnHours + turnMinutes == turnedOn) {
              string q;
              if (minutes < 10)
                q = to_string(hours) + ":0" + to_string(minutes);
              else
                q = to_string(hours) + ":" + to_string(minutes);
              ans.push_back(q);
            }
          }
        }
        return ans;
    }
};