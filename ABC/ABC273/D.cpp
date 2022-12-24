#define _USE_MATH_DEFINES
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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
  ll H, W, rs, cs, N, Q;
  cin >> H >> W >> rs >> cs >> N;
  rs--;
  cs--;
  map<ll, set<ll>> Gr;
  map<ll, set<ll>> Gc;
  for (int i = 0; i < N; i++)
  {
    ll r, c;
    cin >> r >> c;
    r--;
    c--;
    Gr[r].insert(c);
    Gc[c].insert(r);
  }

  cin >> Q;
  for (int i = 0; i < Q; i++)
  {
    char d;
    ll l;
    cin >> d >> l;
    if (d == 'L')
    {
      auto iter = Gr[rs].lower_bound(cs);
      if (iter != Gr[rs].begin())
      {
        iter--;
        cs = max((*iter) + 1, cs - l);
      }
      else
      {
        cs = max(0ll, cs - l);
      }
    }
    else if (d == 'R')
    {
      auto iter = Gr[rs].lower_bound(cs);
      if (iter != Gr[rs].end())
      {
        cs = min((*iter) - 1, cs + l);
      }
      else
      {
        cs = min(W-1, cs + l);
      }
    }
    else if (d == 'U')
    {
      auto iter = Gc[cs].lower_bound(rs);
      if (iter != Gc[cs].begin())
      {
        iter--;
        rs = max((*iter) + 1, rs - l);
      }
      else
      {
        rs = max(0ll, rs - l);
      }
    }
    else
    {
      auto iter = Gc[cs].lower_bound(rs);
      if (iter != Gc[cs].end())
      {
        rs = min((*iter) - 1, rs + l);
      }
      else
      {
        rs = min(H-1, rs + l);
      }
    }
    cout << rs + 1 << " " << cs + 1 << endl;
  }

  return 0;
}