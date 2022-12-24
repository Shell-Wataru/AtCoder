#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;
const long long BASE_NUM = 1000000007;

int solve()
{
  int n;
  scanf("%d", &n);
  if (n == 1){
    cout << "Bob\n";
  }else if(n % 2 == 0){
    ll power = 1;
    ll two = 2;
    while(two < n){
      power++;
      two <<= 1;
    }
    // cout << two << endl;
    // cout << power << endl;
    if (two == n){
      if (power % 2 == 0){
        cout << "Alice\n";
      }else{
        cout << "Bob\n";
      }
    }else{
      cout << "Alice\n";
    }


  }else{
    cout << "Bob\n";
  }
  return 0;
}

int main()
{
  // // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
