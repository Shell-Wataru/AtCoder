#include <iostream>
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

ll count(vector<vector<ll>> &vertical_by_x,vector<ll> &vertical, vector<ll> &y){
  ll ans = 0;
  for(auto ys:vertical_by_x){
    for(auto yy:ys){
      auto big_iter = upper_bound(y.begin(),y.end(),yy);
      auto small_iter = lower_bound(y.begin(),y.end(),yy);
      small_iter--;
      ll lt = *big_iter;
      ll gt = *small_iter;
      // cout << yy <<endl;
      // cout << "(" <<gt << "," <<   lt << ")" << endl;
      auto vertical_big_iter = lower_bound(vertical.begin(),vertical.end(),lt);
      vertical_big_iter--;
      auto vertical_small_iter = upper_bound(vertical.begin(),vertical.end(),gt);
      auto vertical_by_x_big_iter = lower_bound(ys.begin(),ys.end(),lt);
      vertical_by_x_big_iter--;
      auto vertical_by_x_small_iter = upper_bound(ys.begin(),ys.end(),gt);
      ll add_a = (vertical_big_iter - vertical_small_iter + 1);
      ll add_b = (vertical_by_x_big_iter -  vertical_by_x_small_iter + 1);
      // cout << "add_a:" << add_a << "add_b:" << add_b << endl;
      ans += add_a - add_b;
    }
  }
  return ans;
}

int solve()
{
  ll n,m,k;
  scanf("%lld", &n);
  scanf("%lld", &m);
  scanf("%lld", &k);
  vector<ll> x;
  vector<ll> y;
  for(int i = 0;i < n;i++){
    ll xx;
    scanf("%lld",&xx);
    x.push_back(xx);
  }
  for(int i = 0;i < m;i++){
    ll yy;
    scanf("%lld",&yy);
    y.push_back(yy);
  }

  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  vector<vector<ll>> vertical_by_x(n);
  vector<ll> vertical;
  vector<vector<ll>> horizontal_by_y(m);
  vector<ll> horizontal;
  for(int i = 0;i < k;i++){
    ll xp,yp;
    scanf("%lld",&xp);
    scanf("%lld",&yp);
    bool on_vertical = binary_search(x.begin(),x.end(),xp);
    bool on_horizontal = binary_search(y.begin(),y.end(),yp);
    if (on_horizontal && on_vertical){
      continue;
    }else if(on_vertical){
      ll index = lower_bound(x.begin(),x.end(),xp) - x.begin();
      vertical_by_x[index].push_back(yp);
      vertical.push_back(yp);
    }else if (on_horizontal){
      ll index = lower_bound(y.begin(),y.end(),yp) - y.begin();
      horizontal_by_y[index].push_back(xp);
      horizontal.push_back(xp);
    }else{
      continue;
    }
  }
  for(int i = 0; i< n;i++){
    sort(vertical_by_x[i].begin(),vertical_by_x[i].end());
  }
  for(int i = 0; i< m;i++){
    sort(horizontal_by_y[i].begin(),horizontal_by_y[i].end());
  }
  sort(vertical.begin(),vertical.end());
  sort(horizontal.begin(),horizontal.end());
  ll ans = 0;
  // cout << "X" << endl;
  ans +=  count(vertical_by_x,vertical,y);
  // cout << "Y" << endl;
  ans += count(horizontal_by_y,horizontal,x);
  ans /= 2;
  cout << ans << "\n";
  return 0;
}

int main()
{
  int t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}