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
  set<vector<ll>> s;
  for (int i = 0; i < N; i++)
  {
    ll L;
    cin >> L;
    vector<ll> A(L);
    for(int j = 0;j < L;j++){
      cin >> A[j];
    }
    s.insert(A);
  }
  cout << s.size() << endl;
  return 0;
}