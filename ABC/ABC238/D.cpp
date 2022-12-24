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

int solve(){
  ll a,s;
  cin >> a >> s;
  ll x = s - 2*a;
  if (x >= 0 && !(x & a)){
    cout << "Yes\n";
  }else{
    cout << "No\n";
  }
  return 0;
}
int main()
{
  // 整数の入力
  ll T;
  cin >> T;
  for(int i = 0;i < T;i++){
    solve();
  }
  cout << flush;
  return 0;
}
