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
  ll n,m;
  cin >> n >> m;
  if (n > m){
    cout << "No\n";
  }else if (n % 2 == 0){
    ll remain = m - (n-2);
    if (remain % 2 == 0){
      cout << "Yes\n";
      for(int i = 0;i < n-2;i++){
        cout << "1 ";
      }
      cout << remain/2 << " " << remain/2 << "\n";
    }else{
      cout << "No\n";
    }
  }else{
    ll remain = m - (n - 1);
    cout << "Yes\n";
    for(int i = 0;i < n-1;i++){
      cout << "1 ";
    }
    cout << remain << "\n";
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