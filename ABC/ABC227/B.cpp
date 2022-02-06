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
  ll N;
  cin >> N;
  set<ll> can_make;
  for (int i = 1; i <= 400  ; i++)
  {
    for(int j = 1;j <= 400;j++){
      can_make.insert(4*i*j + 3*i + 3*j);
    }
  }
  ll ans = 0;
  for(int i = 0;i < N;i++){
    ll s;
    cin >> s;
    if (can_make.find(s) == can_make.end()){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}