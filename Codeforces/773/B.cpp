#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;

void reverse_a(ll index, vector<ll> &a, ll &total_addition, vector<pair<ll, ll>> &q,vector<ll> &cuts)
{
  for(int i = 0;i <= index;i++){
    q.push_back({2*total_addition+index+i,a[i]});
  }
  cuts.push_back((index+1) * 2);
  total_addition += index + 1;
  reverse(a.begin(),a.begin()+index+1);

}

int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<ll> a(n);
  map<ll, ll> counts;
  for (int i = 0; i < n; i++)
  {
    scanf("%lld", &a[i]);
    counts[a[i]]++;
  }
  for (auto p : counts)
  {
    if (p.second % 2 != 0)
    {
      cout << -1 << endl;
      return 0;
    }
  }
  vector<ll> targets(a);
  sort(targets.begin(), targets.end());
  // for(int i = 0;i < n;i++){
  //   cout << targets[i] << ",";
  // }
  // cout << endl;
  vector<pair<ll, ll>> q;
  vector<ll> cuts;
  ll total_addition = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    ll target;
    if (i >= n / 2)
    {
      target = targets[(i - n / 2) * 2];
    }
    else
    {
      target = targets[i * 2];
    }
    ll target_index = -1;
    for (int j = 0; j < n - 1; j++)
    {
      if (a[j] == target)
      {
        target_index = j;
        break;
      }
    }
    // cout << target << ":" << target_index << endl;
    reverse_a(target_index,a,total_addition,q,cuts);
    reverse_a(i,a,total_addition,q,cuts);
  }
  cout << q.size() << "\n";
  for(auto p:q){
    cout << p.first + 1 << " " << p.second << "\n";
  }
  cout << cuts.size() + 1 << "\n";
  ll total_c = 0;
  for(auto c:cuts){
    cout << c << " ";
    total_c += c;
  }
  cout << n;
  cout << "\n";
  // cout << total_c  << "-" << n + 2*q.size() << endl;
  return 0;
}

int main()
{
  ll t;
  cin >> t;

  for (int i = 1; i <= t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}