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

int solve()
{
  ll n,p;
  string S;
  scanf("%lld", &n);
  scanf("%lld", &p);
  cin >> S;
  reverse(S.begin(),S.end());
  if (p == 2){
    ll ans = 0;
    for(int i = 0;i < n;i++){
        if ((S[i] - '0') % 2 == 0){
            ans += n - i;
        }
    }
    cout << ans << endl;
  }else if(p == 5){
    ll ans = 0;
    for(int i = 0;i < n;i++){
        if ((S[i] - '0') % 5 == 0){
            ans += n - i;
        }
    }
    cout << ans << endl;
  }else{
    ll base = 1;
    vector<ll> total_count(p);
    ll total = 0;
    for(int i = 0;i < n;i++){
        total += (S[i] - '0') * base;
        total %= p;
        base *= 10;
        base %= p;
        total_count[total]++;
    }
    total_count[0]++;
    ll ans = 0;
    for(int i = 0;i < p;i++){
        ans+= total_count[i] *(total_count[i]-1)/2;
    }
    cout << ans << endl;
  }
  return 0;
}

int main()
{
  // // 整数の入力
//   ll t;
//   cin >> t;
//   for (size_t i = 0; i < t; i++)
//   {
  solve();
//   }
//   cout << flush;
  return 0;
}
