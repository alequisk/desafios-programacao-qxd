#include<bits/stdc++.h>
using namespace std;

class SegmentTree {
  public:
    SegmentTree() {}

    template<class Iterator>
    SegmentTree(Iterator begin, Iterator end): _size(end - begin) {
      seg.assign(4 * _size, neutral);
      buildIt(begin, 1, 0, _size - 1);
    }
    
    SegmentTree(vector<int> &v): _size(v.size()) {
      seg.assign(4 * _size, neutral);
      build(v, 1, 0, _size - 1);
    }

    int join(int a, int b) {
      return a ^ b;
    }

    template<class Iterator>
    void buildIt(Iterator v, int node, int tl, int tr) {
      if (tl == tr) {
        seg[node] = *(v + tl);
      } else {
        int tm = tl + (tr - tl) / 2;
        buildIt(v, node << 1, tl, tm);
        buildIt(v, (node << 1) | 1, tm + 1, tr);
        seg[node] = join(seg[node << 1], seg[(node << 1) | 1]);
      }
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
      return query(1, 0, _size - 1, 0, _size - 1) ^ query(1, 0, _size - 1, l, r);
    }

  private:
    int _size, neutral = 0;
    vector<int> seg;
};

class Solution {
  public:
    vector<int> specialXor(int n, int q, int a[], vector<int> query[]) {
      SegmentTree s(a, a + n);
      vector<int> answer(q);
      for (int i = 0; i < q; ++i) {
        answer[i] = s.query(query[i][0] - 1, query[i][1] - 1);
      }
      return answer;
    }
};


int main () {
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    int l, r;
    vector<int> query[q];
    for (int i = 0; i < q; ++i) {
      cin >> l >> r;
      query[i].push_back(l);
      query[i].push_back(r);
    }
    Solution sol;
    vector<int> ans = sol.specialXor(n, q, a, query);
    for (int u: ans) {
      cout << u << "\n";
    }
  }
  return 0;
}