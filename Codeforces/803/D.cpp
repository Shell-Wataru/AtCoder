#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

vector<ll> query(ll l,ll r){
    cout  << "? "<< l+1 << " " << r << endl;
    vector<ll> ans(r-l);
    for(int i = 0;i < r-l;i++){
        cin >> ans[i];
    }
    return ans;
}

ll answer(ll l,ll r){
    if (l+1 == r){
        return l;
    }
    ll center = (l+r)/2;
    vector<ll> sorted = query(l,center);
    ll count = 0;
    for(auto s:sorted){
        if (l+1 <= s && s <= center){
            count++;
        }
    }
    if (count%2 == 0){
        return answer(center,r);
    }else{
        return answer(l,center);
    }
}

int solve()
{
  ll n;
  scanf("%lld", &n);
  ll ans = answer(0,n) + 1;
  cout << "! " << ans <<endl;
  return 0;
}

int main()
{
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
