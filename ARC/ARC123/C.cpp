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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

int main()
{
  ll N;
  cin >> N;
  for(int i = 0;i < N;i++){
    string S;
    cin >> S;
    ll k = 0;
    for(auto d:S){
      ll n = d -'0';
      if (n == 0){
        k = max(k,4ll);
      }else if (0 <= n && n <= 3){
        k = max(k,1ll);
      }else if (4 <= n && n <= 6){
        k = max(k,2ll);
      }else if (7 <= n && n <= 9){
        k = max(k,3ll);
      }
    }
    cout << k << endl;
  }
  return 0;
}
