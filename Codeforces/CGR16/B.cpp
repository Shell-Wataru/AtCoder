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

vector<ll> xor_sum(1000000,0);
int solve()
{
  string S;
  cin >> S;
  ll count = 0;
  char last_char = '-';
  for(auto c:S){
    if (last_char != c){
      last_char = c;
      count++;
    }
  }
  if (S[0] == '1'){
    count--;
  }
  if (count >= 3){
    cout << "2\n";
  }else if (count == 0){
    cout << "0\n";
  }else{
    cout << "1\n";
  }
  return 0;
}

int main()
{
  for(int i = 1;i < 1000000;i++){
    xor_sum[i] = xor_sum[i-1]^i;
  }
  ll t;
  cin >> t;

  for (int i = 1; i <= t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}