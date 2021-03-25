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
#include <set>
using namespace std;
using ll = long long;

int main()
{
  // 整数の入力
  ll A, B;
  cin >> A >> B;
  vector<ll> counts(B - A + 1,1);
  ll cards = B - A + 1;
  for (ll i = B - A + 1;i >= 1; i--)
  {
    ll to = B / i;
    ll from = (A -1)/ i;
    ll cannot_select = to - from;
    cout << i << ":" << cannot_select << endl;
    ll current_count = (1ll<<(cards-cannot_select))*((1ll<<cannot_select) - cannot_select - 1);
    for(int j = 2;i * j <= B - A + 1;j++ ){
      current_count -= counts[i*j];
    }
    counts[i] = current_count;
  }
  // for(int i = 1;i <= B-A+1;i++){
  //   cout << i << ":" << counts[i] << endl;
  // }
  cout << cards + counts[1] + 1 << endl;
  return 0;
}