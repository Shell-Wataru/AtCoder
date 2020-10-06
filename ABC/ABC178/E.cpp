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
  ll N;
  cin >> N;
  vector<ll> plusplus;
  vector<ll> plusminus;
  for(int i = 0;i < N;i++){
      ll x,y;
      cin >> x >> y;
      plusplus.push_back(x+y);
      plusminus.push_back(x-y);
  }
  sort(plusplus.begin(),plusplus.end());
  sort(plusminus.begin(),plusminus.end());
  cout << max(plusplus.back() - plusplus.front(), plusminus.back() - plusminus.front()) << endl;
  return 0;
}
