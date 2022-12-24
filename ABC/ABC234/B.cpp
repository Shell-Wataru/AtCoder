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
  vector<pair<ll,ll>> points(N);
  double ans = 0;
  for(int i = 0;i < N;i++){
    cin >> points[i].first >> points[i].second;
  }
  for(int i = 0;i < N;i++){
    for(int j = i+1;j < N;j++){
      ans = max(ans,hypot(points[i].first - points[j].first,points[i].second - points[j].second));
    }
  }
  cout << fixed << setprecision(12) << ans << endl;
  return 0;
}