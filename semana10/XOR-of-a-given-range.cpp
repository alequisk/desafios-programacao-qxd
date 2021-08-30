#include<bits/stdc++.h>
using namespace std;

class SegmentTree {
  public:
    SegmentTree() {}
    SegmentTree(int n): _size(n) {
      seg.assign(4 * _size, neutral);
    }
    SegmentTree(vector<int> &v): _size(v.size()) {
      seg.assign(4 * _size, neutral);
      build(v, 1, 0, _size - 1);
    }

    int join(int a, int b) {
      return a ^ b;
    }

    void build(vector<int> &v, int node, int tl, int tr) {
      if (tl == tr) {
        seg[node] = v[tl];
      } else {
        int tm = tl + (tr - tl) / 2;
        build(v, node << 1, tl, tm);
        build(v, (node << 1) | 1, tm + 1, tr);
        seg[node] = join(seg[node << 1], seg[(node << 1) | 1]);
      }
    }

    int query(int node, int tl, int tr, int l, int r) {
      if (l > r) return neutral;
      if (tl == l and tr == r) {
        return seg[node];
      }
      int tm = tl + (tr - tl) / 2;
      return join(
        query(node << 1, tl, tm, l, min(tm, r)),
        query((node << 1) | 1, tm + 1, tr, max(tm + 1, l), r)
      );
    }

    int query(int l, int r) {
      if (l > r) swap(l, r);
      return query(1, 0, _size - 1, l, r);
    }

  private:
    int _size, neutral = 0;
    vector<int> seg;
};

class Solution {
  public:
    int getXor(vector<int>& nums, int a, int b) {
      SegmentTree s(nums);
      return s.query(a, b);
    }
};

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> nums(n);
    for (int &x: nums) {
      cin >> x;
    }
    if (a > b) swap(a, b);
    Solution sol;
    int ans = sol.getXor(nums, a, b);
    cout << ans << "\n";
  }

  return 0;
}