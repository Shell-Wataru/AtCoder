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

using namespace std;
using ll = long long;

ll query(ll u,ll v){
  cout << "? " << u + 1 << " " << v + 1 << endl;
  ll ret;
  cin >> ret;
  return ret;
}

int main()
{
  ll N;
  cin >> N;
  bool is_neighbor = true;
  ll minimum_distance = numeric_limits<ll>::max();
  ll maximum_a = 0;
  ll maximum_b = 0;
  for(int i = 2;i < N;i++){
    ll a = query(0,i);
    ll b = query(1,i);
    maximum_a = max(maximum_a,a);
    maximum_b = max(maximum_b,b);
    minimum_distance = min(minimum_distance,a+b);
    if (abs(a-b) != 1){
      is_neighbor = false;
    }
  }
  if (is_neighbor){
    if (N == 4){
      ll twothree = query(2,3);
      if (twothree == 1 && max(maximum_a,maximum_b) == 2){
        cout <<"! " << minimum_distance << endl;
      }else{
        cout <<"! " << 1 << endl;
      }
    }else{
      cout <<"! " << 1 << endl;
    }

  }else{
    cout << "! " << minimum_distance << endl;
  }
  return 0;
}
