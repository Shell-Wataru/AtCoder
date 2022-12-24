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

using namespace std;
using ll = long long;

int main()
{
  ll n;
  cin >>n;
  vector<ll> a(n);
  vector<ll> b(n);
  ll total_a_xor = 0;
  ll total_b_xor = 0;
  ll total_a_sum = 0;
  ll total_b_sum = 0;
  for(int i = 0;i < n;i++){
    cin >> a[i];
  }

  for(int i = 0;i < n;i++){
    cin >> b[i];
  }
  ll ans = 0;
  for(int i = 0;i < 30;i++){
    ll a_count = 0;
    ll b_count = 0;
    for(int j = 0;j < n;j++){
        if (a[j] & (1ll<<i)){
            a_count++;
        }
        if (b[j] & (1ll<<i)){
            b_count++;
        }
    }
    // cout << i << ":" << endl;
    // cout << a_count << endl;
    // cout << b_count << endl;
    vector<ll> sub_a(n);
    vector<ll> sub_b(n);
    for(int j = 0;j < n;j++){
        sub_a[j] = ((1ll<<i)-1) & a[j];
        sub_b[j] = ((1ll<<i)-1) & b[j];
    }
    sort(sub_b.begin(),sub_b.end());
    ll kuriage_count = 0;
    for(int j = 0;j < n;j++){
        ll count = sub_b.end()-lower_bound(sub_b.begin(),sub_b.end(),(1ll<<i)-sub_a[j]);
        kuriage_count += count;
    }
    if ( (a_count*(n-b_count) + (n-a_count)*b_count + kuriage_count) % 2 == 1){
        ans += 1ll<<i;
    }
  }

  cout << ans << endl;
  return 0;
}
