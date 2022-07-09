#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) 42
#define debugif(x,y...) 42
#endif
using namespace std;
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define _FOR(i, a, b) for(int i = (a); i >= (b); --i)
#define INT_INF 0x3f3f3f3f
#define LLONG_INF 0x3f3f3f3f3f3f3f3f
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  FOR(t, 1, T) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    char pre = 'a';
    int res1 = 0, res2 = 0;
    for(int i = 0; i < n; i += 2) {
      if(s[i] != s[i + 1]) {
        res1++;
      } else if(pre != s[i]) {
        pre = s[i];
        res2++;
      }
    }
    if(!res2) res2++;
    cout << res1 << ' ' << res2 << '\n';
  }
  return 0;
}