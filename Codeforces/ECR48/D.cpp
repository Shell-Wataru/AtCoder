#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
ll BASE_NUM = 998244353;

pair<ll,ll> make_by_two(ll u,ll v){
  ll first = 0;
  ll second = 0;
  for(int i = 0;i< 60;i++){
    bool ubit = u & 1<<i;
    bool vbit = v & 1<<i;
    if (ubit && vbit){
      first += 1<<i;
    }else if(ubit && !vbit){

    }else if(!ubit && vbit){
      first += 1<<(i-1);
      second += 1<<(i-1);
    }else if(!ubit && !vbit){
    }
  }
};

int solve()
{
  ll a, b;
  cin >> a >> b;
  if (a == 0 && b == 0)
  {
    cout << 0 << endl;
  }
  else if (a == b)
  {
    cout << 1 << endl;
    cout << a << endl;
  }else if ( a % 2 == 0 && b % 2 == 1){
    cout << -1 << endl;
  }else{
    ll first = (b+1)/2;
    ll second = b/2;
    ll third = 0;
    for(int i = 1;i < 60;i++){
      if (a & (1<<i)){
        if (!(first & (1<<(i-1))) && !(first & (1<<(i-1)))){

        }
      }
    }
  }
  return 0;
}

int main()
{
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
  solve();
  // }
  return 0;
}