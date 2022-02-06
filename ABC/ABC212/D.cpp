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

int main()
{
  // 整数の入力
  ll Q;
  cin >> Q;
  priority_queue<ll,vector<ll>, greater<ll>> q;
  ll base = 0;
  for(int i = 0;i < Q;i++){
    ll p;
    cin >> p ;
    if (p == 1){
      ll x;
      cin >> x;
      q.push(x- base);
    }else if (p == 2){
      ll x;
      cin >> x;
      base += x;
    }else{
      cout << q.top() + base << endl;
      q.pop();
    }
  }
  return 0;
}
