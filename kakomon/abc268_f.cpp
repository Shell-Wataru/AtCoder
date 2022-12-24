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
#include <unordered_map>
#include <unordered_set>

using namespace std;
using ll = long long;

int main()
{
  ll N;
  cin >> N;
  vector<pair<ll,ll>> P(N);
  ll ans = 0;
  for(int i = 0;i < N;i++){
    string S;
    cin >> S;
    ll point =0;
    ll x = 0;
    for(auto c:S){
        if (c == 'X'){
            x++;
        }else{
            ll p = c - '0';
            point += p;
            ans +=  p*x;
        }
    }
    P[i] = {x,point};
  }
  sort(P.begin(),P.end(),[](pair<ll,ll> l, pair<ll,ll> r){
    return l.first*r.second > r.first*l.second;
  });
  ll total_x = 0;
  for(int i = 0;i < N;i++){
    ans += total_x*P[i].second;
    total_x += P[i].first;
  }
  cout << ans << endl;
  return 0;
}
