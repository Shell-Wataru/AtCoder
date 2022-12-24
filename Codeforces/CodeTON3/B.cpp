#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;

int solve()
{
  ll n;
  scanf("%lld", &n);
  string S;
  cin >> S;
  ll continues = 0;
  ll max_continues = 0;
  ll zeros = 0;
  ll ones = 0;
  ll last = -1;
  for(int i = 0;i < n;i++){
    if (S[i] == '1'){
      ones++;
    }else if (S[i] == '0'){
      zeros++;
    }
    if (S[i]-'0' == last){
      continues++;
      max_continues = max(max_continues,continues);
    }else{
      continues = 1;
      last = S[i]-'0';
      max_continues = max(max_continues,continues);
    }
  }
  cout << max(ones*zeros,max_continues*max_continues) << "\n";
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