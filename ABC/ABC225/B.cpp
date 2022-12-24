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
  vector<ll> G(N,0);
  for (int i = 0; i < N-1; i++)
  {
    ll a,b;
    cin >> a >> b;
    a--;b--;
    G[a]++;
    G[b]++;
    if (G[a] == N- 1 || G[b] == N-1){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}