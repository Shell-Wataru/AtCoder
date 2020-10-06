#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
ll BASE_NUM = 998244353;

int main()
{
  ll x_0, y_0, a_x, a_y, b_x, b_y;
  ll x_s, y_s, t;
  cin >> x_0 >> y_0 >> a_x >> a_y >> b_x >> b_y;
  cin >> x_s >> y_s >> t;
  vector<pair<ll, ll>> coordinates;
  coordinates.push_back({x_0, y_0});
  pair<ll, ll> last = coordinates.back();
  while (last.first - x_s <= t || last.second - y_s <= t)
  {
    last = {last.first * a_x + b_x, last.second * a_y + b_y};
    coordinates.push_back(last);
  }
  ll max_counts = 0;
  // cout << coordinates.size() << endl;
  for (int i = coordinates.size() - 1; i >= 0; i--)
  {
    ll remain_t = t;
    pair<ll, ll> current{x_s, y_s};
    ll count = 0;
    // cout << "start" << coordinates[i].first  << "," << coordinates[i].second << endl;
    for (int j = i; j >= 0; j--)
    {
      remain_t -= abs(coordinates[j].first - current.first) + abs(coordinates[j].second - current.second);
      if (remain_t < 0){
        break;
      }else{
        // cout << "current" << coordinates[j].first  << "," << coordinates[j].second << "remain" << remain_t << endl ;
        count++;
        current = coordinates[j];
      }
    }
    max_counts = max(count,max_counts);
  }

  for (int i = 0; i < coordinates.size() ; i++)
  {
    ll remain_t = t;
    pair<ll, ll> current{x_s, y_s};
    ll count = 0;
    // cout << "start" << coordinates[i].first  << "," << coordinates[i].second << endl;
    for (int j = i; j < coordinates.size(); j++)
    {
      remain_t -= abs(coordinates[j].first - current.first) + abs(coordinates[j].second - current.second);
      if (remain_t < 0){
        break;
      }else{
        // cout << "current" << coordinates[j].first  << "," << coordinates[j].second << "remain" << remain_t << endl ;
        count++;
        current = coordinates[j];
      }
    }
    max_counts = max(count,max_counts);
  }
  cout << max_counts << endl;
  return 0;
}