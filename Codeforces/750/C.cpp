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
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

int solve()
{
  ll n;
  string S;
  scanf("%lld", &n);
  cin >> S;
  ll ans = numeric_limits<ll>::max();

  for (int i = 0; i < 26; i++)
  {
    ll removes = 0;
    ll front = 0;
    ll back = n -1;
    while(front < back)
    {
      if (S[front] - 'a' == i && S[back] - 'a' == i)
      {
        front++;
        back--;
      }
      else if (S[front] - 'a' != i && S[back] - 'a' == i)
      {
        back--;
        removes++;
      }
      else if (S[front] - 'a' == i && S[back] - 'a' != i)
      {
        front++;
        removes++;
      }
      else if (S[front]  ==  S[back])
      {
        front++;
        back--;
      }else{
        removes = numeric_limits<ll>::max();
        break;
      }
    }
    ans = min(ans,removes);
  }
  if (ans == numeric_limits<ll>::max()){
    cout << -1 << "\n";
  }else{
    cout << ans << "\n";
  }

  return 0;
}

int main()
{
  // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
