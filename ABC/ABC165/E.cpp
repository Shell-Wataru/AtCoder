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
ll BASE_NUM = 1000000007;

int main()
{
  // 整数の入力
  ll N, M;
  cin >> N >> M;

  ll NN;
  if (N % 2 == 0)
  {
    NN = N + 1;
  }
  else
  {
    NN = N;
  }
  vector<pair<ll, ll>> ans;
  for (int i = 1; i <= NN / 2; i++)
  {
    ans.push_back({i, NN - i});
  }

  for (int i = 0; i < M; i++)
  {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
  return 0;
}
