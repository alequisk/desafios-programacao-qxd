class Solution {
public:
  vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    int sz = arr.size();
    vector<int> psa(sz + 1, 0);
    for (int i = 0; i < sz; ++i) {
      psa[i + 1] = arr[i] ^ psa[i];
    }
    
    vector<int> answer;
    
    for (vector<int> x: queries) {
      int left = psa[x[0]];
      int right = psa[sz] ^ psa[x[1] + 1];
      answer.push_back(psa[sz] ^ left ^ right);
    }
    
    return answer;
  }
};