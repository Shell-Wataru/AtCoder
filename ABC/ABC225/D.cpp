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
#include <stack>

using namespace std;
using ll = long long;


int main()
{
  // 整数の入力
  ll N ,Q;
  cin >> N >> Q;
  vector<ll> trains_from(N,-1);
  vector<ll> trains_to(N,-1);
  for(int i = 0; i < Q;i++){
    ll t;
    cin >> t;
    if (t == 1){
      ll x,y;
      cin >> x >> y;
      x--;
      y--;
      trains_from[y] = x;
      trains_to[x] = y;
    }else if(t == 2){
      ll x,y;
      cin >> x >> y;
      x--;
      y--;
      trains_from[y] = -1;
      trains_to[x] = -1;
    }else{
      ll x;
      cin >> x;
      x--;
      vector<ll> ans;
      while(trains_from[x] != -1){
        x = trains_from[x];
      }
      while(x != -1){
        ans.push_back(x);
        x = trains_to[x];
      }
      cout << ans.size();
      for(auto a:ans){
        cout << " " << a + 1;
      }
      cout << "\n";
    }
  }
  cout << flush;
  return 0;
}
