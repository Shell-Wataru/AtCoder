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
  vector<ll> counts(N,0);

  for(int i = 0;i < 4*N-1;i++){
    ll a;
    cin >> a;
    a--;
    counts[a]++;
  }
  for(int i = 0;i < N;i++){
    if (counts[i] == 3){
      cout << i+1 << endl;
    }
  }
  return 0;
}