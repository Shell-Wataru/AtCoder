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
using namespace std;
using ll = long long;

int solve()
{
    ll N;
    cin >> N;
    vector<pair<ll,ll>> P(N);
    for(int i = 0;i < N;i++){
      cin >> P[i].first >> P[i].second;
    }
    ll target = 0;
    for(int i = 0;i < N;i++){
      ll x1  = P[i].first - P[0].first;
      ll y1  = P[i].second - P[0].second;
      ll x2  = P[(i+1)%N].first - P[0].first;
      ll y2  = P[(i+1)%N].second - P[0].second;
      target += abs(x1*y2 - x2*y1);
    }
    ll ans = numeric_limits<ll>::max();
    ll b = 1;
    ll s = 0;
    for(int i = 0;i < N;i++){
      ans = min(ans,abs(target - 4*s));
      while(4*s < target){
        ll x1  = P[b].first - P[i].first;
        ll y1  = P[b].second - P[i].second;
        ll x2  = P[(b+1)%N].first - P[i].first;
        ll y2  = P[(b+1)%N].second - P[i].second;
        s += abs(x1*y2 - x2*y1);
        ans = min(ans,abs(target - 4*s));
        b = (b+1) % N;
      }
      ll x1  = P[i].first - P[b].first;
      ll y1  = P[i].second - P[b].second;
      ll x2  = P[(i+1)%N].first - P[b].first;
      ll y2  = P[(i+1)%N].second - P[b].second;
      s -= abs(x1*y2 - x2*y1);
    }
    // cout << s << endl;
    cout << ans << endl;
    return 0;
}

int main()
{
    // ll T;
    // cin >> T;
    // for (int i = 0; i < T; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}
