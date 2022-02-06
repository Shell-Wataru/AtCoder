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


int main()
{
  // 整数の入力
  ll N;
  cin >> N;
  vector<pair<ll,ll>> points(N);
  for(int i = 0;i < N;i++){
    cin >>points[i].first >> points[i].second;
  }
  set<pair<ll,ll>> magics;
  for(int i = 0;i < N;i++){
    for(int j =0 ;j < N;j++){
      if (i == j ){
        continue;
      }
      ll x = points[i].first - points[j].first;
      ll y = points[i].second - points[j].second;
      magics.insert({x/gcd(x,y),y/gcd(x,y)});
    }
  }
  cout << magics.size() << endl;
  return 0;
}
