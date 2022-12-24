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
  ll N,M,T;
  cin >> N >> M >> T;
  vector<ll> A(N-1);
  vector<ll> bonuses(N-1,0);
  for(int i = 0;i < N-1;i++){
    cin >> A[i];
  }
  for(int i = 0;i < M;i++){
    ll x,y;
    cin >> x >> y;
    x--;
    bonuses[x] = y;
  }
  ll ans = 0;
  for(int i = 0;i < N-1;i++){
    T += bonuses[i];
    T -= A[i];
    if (T > 0){
      ans++;
    }else{
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes"<< endl;
  return 0;
}