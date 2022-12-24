#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <set>
#include <atcoder/string>
#include <unordered_map>
using namespace std;
using ll = long long;
using namespace atcoder;

int main()
{
  ll n;
  cin >> n;
  int h = 1;
  while ((1 << h) <= n)
    ++h;
  vector<int> height;
  height.assign((1 << h), 0);
  vector<pair<ll, ll>> ranges;
  vector<vector<ll> > dat;
  dat.assign(h, vector<ll>(n));
  ll index = 0;
  for (int i = 2; i < (1 << h); i++){
    height[i] = height[i >> 1] + 1;
  }

  for (int i = 0; i < n; ++i){
    dat[0][i] = index;
    index++;
    ranges.push_back({i,i+1});
  }

  for (int i = 1; i < h; ++i)
  {
    int s = (1 << i);
    for (ll j = 0; j < n; j += (s << 1))
    {
      ll t = min(j + s, n);
      dat[i][t - 1] = index;
      index++;
      ranges.push_back({t-1,t});
      for (int k = t - 2; k >= j; --k){
        dat[i][k] = index;
        index++;
        ranges.push_back({k,t});
      }

      if (n <= t)
        break;
      dat[i][t] = index;
      index++;
      ranges.push_back({t,t+1});
      for (int k = t + 1; k < min(t + s, n); ++k){
        dat[i][k] = index;
        index++;
        ranges.push_back({t,k+1});
      }
    }
  }
  cout << ranges.size() << endl;
  for(int i = 0;i < ranges.size();i++){
    cout << ranges[i].first + 1 << " " << ranges[i].second << endl;
  }
  ll Q;
  cin >> Q;
  for(int i = 0;i < Q;i++){
    ll l,r;
    cin >> l >> r;
    l--;

    if (l >= --r){
      // cerr << "!" << ranges[dat[0][l]].first + 1 << " " << ranges[dat[0][l]].second<< endl;
      cout << dat[0][l] + 1<< " " << dat[0][l]+1 <<  endl;
    }else{;
      // cerr << "!" << ranges[dat[height[l^r]][l]].first+1 << " " << ranges[dat[height[l^r]][r]].second << endl;
      cout << dat[height[l^r]][l] + 1<< " " << dat[height[l^r]][r]+1 <<  endl;
    }
  }
  return 0;
}
