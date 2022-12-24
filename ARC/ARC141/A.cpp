#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int solve()
{
  string N;
  cin >> N;
  ll ans = 0;
  ll M = N.size();
  for(int i = 0;i < M-1;i++){
    ans *= 10;
    ans += 9;
  }
  for(int i = 1;i < M;i++){
    if (M % i  == 0){
      string base;
      for(int j = 0;j < i;j++){
        base += N[j];
      }
      string temp;
      for(int j = 0;j < M/i;j++){
        temp += base;
      }
      if (temp > N){
        ll current = stoll(base);
        current--;
        temp = "";
        for(int j = 0;j < M/i;j++){
          temp += to_string(current);
        }
      }
      ans = max(ans,stoll(temp));
    }
  }
  cout << ans << "\n";
  return 0;
}
int main()
{
  ll T;
  cin >> T;
  for(int i = 0;i < T;i++){
  solve();
  }
  cout << flush;
  return 0;
}