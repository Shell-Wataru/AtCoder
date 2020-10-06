#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>
#include <string>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
  double x,y;
  cin >> x >> y;
  ll N;
  cin >> N;
  double ans = numeric_limits<double>::max();
  vector<pair<ll,ll>> points(N);
  for(int i = 0;i < N;i++){
    cin >> points[i].first;
    cin >> points[i].second;
  }
  for(int i = 0;i < N;i++){
    ll a = (points[i].second - points[(i+1)% N].second);
    ll b= -(points[i].first - points[(i+1)% N].first);
    ll c = - (a * points[i].first + b * points[i].second);
    double distance = abs(a * x + b * y + c)/sqrt(a*a + b* b);
    ans = min(ans,distance);
  }
  cout << fixed << setprecision(12) << ans << endl;
  return 0;
}