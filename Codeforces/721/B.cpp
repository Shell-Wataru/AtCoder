#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>

using namespace std;
using ll = long long;
const long long BASE_NUM = 1000000007;

int solve()
{
  ll n;
  scanf("%lld", &n);
  string s;
  cin >> s;
  if (n % 2 == 0){
    cout << "BOB\n";
  }else{

    ll zero_count = 0;
    bool is_center_zero = s[n/2] == '0';
    for(auto c:s){
      if (c == '0'){
        zero_count++;
      }
    }
    // cout << is_center_zero << endl;
    // cout <<zero_count << endl;
    if (is_center_zero){
      zero_count--;
      if (zero_count == 0){
        cout << "BOB\n";
      }else{
        cout << "ALICE\n";
      }
    }else{
      cout << "BOB\n";
    }
  }
  return 0;
}

int main()
{
  ll t;
  cin >> t;

  for (int i = 1; i <= t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}