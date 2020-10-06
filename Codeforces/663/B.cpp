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

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
  ll n,m;
  cin >> n;
  cin >> m;
  vector<string>  G(n);
  for (size_t i = 0; i < n; i++)
  {
    cin >> G[i];
  }
  ll ope = 0;
  for(int i = 0;i < n-1;i++){
    if (G[i][m-1] == 'R'){
      ope++;
    }
  }
  for(int i = 0;i < m-1;i++){
    if (G[n-1][i] == 'D'){
      ope++;
    }
  }
  cout << ope << endl;
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
  return 0;
}
