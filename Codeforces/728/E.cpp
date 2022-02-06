#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;
const long long BASE_NUM = 1000000007;

int solve()
{
  int n,m;
  scanf("%d", &n);
  scanf("%d", &m);
  vector<ll> k(n);
  vector<pair<ll,ll>> l(n);
  vector<pair<ll,ll>> r(n);
  SegmentTree<monoid_max> seg_la(n);
  SegmentTree<monoid_min> seg_lb(n);
  SegmentTree<monoid_max> seg_ra(n);
  SegmentTree<monoid_min> seg_rb(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&k[i]);
    scanf("%lld",&l[i].first);
    scanf("%lld",&l[i].second);
    scanf("%lld",&r[i].first);
    scanf("%lld",&r[i].second);
    // compress.add(k[i]);
    // compress.add(l[i].first);
    // compress.add(r[i].first);
    // compress.add(l[i].second);
    // compress.add(r[i].second);
  }
  // compress.build();

  return 0;
}

int main()
{
  // // 整数の入力
  ll t = 1;
//   cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
