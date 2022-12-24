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
  vector<bool> used(3000,false);
  for(int i = 0;i < N;i++){
    ll a;
    cin >> a;
    used[a] = true;
  }
  for(int i = 0;i <= N;i++){
    if (!used[i]){
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}