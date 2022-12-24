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
  vector<ll> A(N,-1);
  for(int i = 0;i < N-1;i++){
    cin >> A[i+1];
    A[i+1]--;
  }
  ll current = N-1;
  ll ans = 0;
  while(current != 0){
    ans++;
    current = A[current];
  }
  cout << ans << endl;
  return 0;
}