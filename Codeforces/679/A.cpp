#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator>

using namespace std;
using ll = long long;

struct Fret
{
  ll fret, index, used_string;
   bool operator<(const Fret& rhs) const
    {
      if (fret != rhs.fret){
        return fret < rhs.fret;
      }else{
        return used_string > rhs.used_string;
      }

    }
};
int solve()
{
  vector<ll> a(6);
  for (size_t i = 0; i < 6; i++)
  {
    scanf("%lld", &a[i]);
  }
  sort(a.begin(), a.end());
  ll n;
  cin >> n;
  vector<ll> notes(n);
  for (size_t i = 0; i < n; i++)
  {
    scanf("%lld", &notes[i]);
  }
  sort(notes.begin(), notes.end());
  ll min_fret = numeric_limits<ll>::max();
  ll ans = numeric_limits<ll>::max();
  priority_queue<Fret> q;
  for (ll i = 0; i < n; i++)
  {
    q.push({notes[i] - a[0],i,0});
    min_fret = min(min_fret,notes[i] - a[0]);
  }

  do{
    auto d =q.top();
    // cout << "==" << endl;
    // cout << d.fret << endl;
    // cout << d.index << endl;
    // cout << d.used_string << endl;
    ans = min(d.fret - min_fret,ans);
    q.pop();
    q.push({notes[d.index] - a[d.used_string+1],d.index,d.used_string+1});
    min_fret = min(min_fret,notes[d.index] - a[d.used_string+1]);
  }while(q.top().used_string != 5);
  ans = min(q.top().fret - min_fret,ans);
  cout << ans << endl;
  return 0;
}

int main()
{
  // 整数の入力
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
  solve();
  // }
  return 0;
}