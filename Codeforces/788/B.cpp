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

int solve()
{
  ll n;
  scanf("%lld",&n);
  string S;
  cin >> S;
  vector<ll> lengths;
  ll k;
  scanf("%lld",&k);
  vector<bool> special(26,false);
  for(int i = 0;i < k;i++){
    char c;
    cin >> c;
    special[c - 'a'] = true;
  }
  ll count = 0;
  for(int i = 0;i < n;i++){
    if (special[S[i] - 'a']){
      lengths.push_back(count);
      count = 0;
    }else{
      count++;
    }
  }
  if (lengths.size() == 0){
    cout << 0 << "\n";
  }else{
    ll ans = 0;
    ll ans_index = 0;
    for(int i = 0;i < lengths.size();i++){
      if (lengths[i] >= ans){
        ans = lengths[i];
        ans_index = i;
      }
    }
    if (ans_index == 0){
      cout << ans << "\n";
    }else{
      cout << ans + 1<< "\n";
    }
  }
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