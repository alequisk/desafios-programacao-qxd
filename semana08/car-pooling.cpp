class Solution {
public:
  struct P {
    int type;
    int pos;
    int qtd;
    
    P() {}
    P(int type, int pos, int qtd): type(type), qtd(qtd), pos(pos) {}
  };

  bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<P> line;
    for (vector<int> a: trips) {
      line.push_back(P(0, a[1], a[0]));
      line.push_back(P(1, a[2], a[0]));
    }
    auto cmp = [](P a, P b) -> bool {
      return a.pos < b.pos;
    };
    sort(line.begin(), line.end(), cmp);
    int index = 0, sz = line.size();
    int acc = 0, ok = true;
    while (index < sz) {
      int j = index;
      acc += line[index].type == 0 ? line[index].qtd : -line[index].qtd;
      while (j + 1 < sz && line[j + 1].pos == line[index].pos) {
        ++j;
        acc += line[j].type == 0 ? line[j].qtd : -line[j].qtd;
      }
      if (acc > capacity) ok = false;
      
      index = j + 1;
    }
    return ok;
  }
};