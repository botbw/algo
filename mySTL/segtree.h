#ifndef SEGTREE_H
#define SEGTREE_H

#include <vector>

#define lc(x) ((x) * 2)
#define rc(x) ((x) * 2 + 1)
#define len(x) (t[(x)].r - t[(x)].l + 1)

template <int N, typename tag, void(*push_up)(tag&, const tag&, const tag&), void(*push_down)(tag&, tag&, int, tag&, int) = nullptr>
class segtree {
  struct node {
    int l, r;
    tag val;
  };

  int lo, hi;
  bool noPd;
  node t[N * 4];

  void build(int x, int l, int r, const vector<tag> &init) {
    t[x] = {l, r, tag()};
    if(l == r) {
      t[x] = {l, r, init[l]};
      return;
    }
    int mi = (l + r) / 2;
    build(lc(x), l, mi, init);
    build(rc(x), mi + 1, r, init);
    push_up(t[x].val, t[lc(x)].val, t[rc(x)].val);
  }

  void build(int x, int l, int r, const tag* init) {
    t[x] = {l, r, tag()};
    if(l == r) {
      t[x] = {l, r, init[l]};
      return;
    }
    int mi = (l + r) / 2;
    build(lc(x), l, mi, init);
    build(rc(x), mi + 1, r, init);
    push_up(t[x].val, t[lc(x)].val, t[rc(x)].val);
  }
  
  template <typename modifier>
  void _update(int x, int l, int r, const modifier &m) {
    if(l <= t[x].l && t[x].r <= r) {
      m(t[x].l, t[x].r, t[x].val);
      return;
    }
    if(!noPd) push_down(t[x].val, t[lc(x)].val, len(lc(x)), t[rc(x)].val, len(rc(x)));
    int mi = (t[x].l + t[x].r) / 2;
    if(l <= mi) _update(lc(x), l, r, m);
    if(r >= mi + 1) _update(rc(x), l, r, m);
    push_up(t[x].val, t[lc(x)].val, t[rc(x)].val);
  }

  tag _query(int x, int l, int r) {
    if(l <= t[x].l && t[x].r <= r) return t[x].val;
    if(!noPd) push_down(t[x].val, t[lc(x)].val, len(lc(x)), t[rc(x)].val, len(rc(x)));
    int mi = (t[x].l + t[x].r) / 2;
    if(l <= mi && r >= mi + 1) {
      tag L = _query(lc(x), l, r);
      tag R = _query(rc(x), l, r);
      tag ret;
      push_up(ret, L, R);
      return ret;
    } else if(l <= mi) return _query(lc(x), l, r);
    else return _query(rc(x), l, r);
  }


 public:
  segtree(int _lo, int _hi): lo(_lo), hi(_hi), noPd(push_down == nullptr) {
    int n = hi - lo + 1;
    vector<tag> init(n + 1, tag());
    build(1, lo, hi, init);
  }

  segtree(int _lo, int _hi, const vector<tag> &init): lo(_lo), hi(_hi), noPd(push_down == nullptr) {
    build(1, lo, hi, init);
  }

  segtree(int _lo, int _hi, const tag *init): lo(_lo), hi(_hi), noPd(push_down == nullptr) {
    build(1, lo, hi, init);
  }

  template <typename modifier>
  void update(int x, const modifier &m) {
    assert(lo <= x && x <= hi);
    _update(1, x, x, m);
  }

  template <typename modifier>
  void update(int l, int r, const modifier &m) {
    _update(1, l, r, m);
  }

  tag query(int x) {
    return _query(1, x, x);
  }

  tag query(int l, int r) {
    return _query(1, l, r);
  }
};

#undef lc
#undef rc
#undef len

#endif
