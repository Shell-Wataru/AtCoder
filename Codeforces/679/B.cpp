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
const ll BASE_NUM = 1000000007;

int solve()
{
  ll n;
  cin >> n;
  vector<string> G(n);
  for (size_t i = 0; i < n; i++)
  {
    cin >> G[i];
  }
  if (G[0][1] == G[1][0] && G[0][1] == G[n-1][n-2] && G[0][1] == G[n-2][n-1]){
    cout << 2 << "\n";
    cout << "1 2" << "\n";
    cout << "2 1" << "\n";
    cout << flush;
  }else if (G[0][1] != G[1][0] && G[0][1] == G[n-1][n-2] && G[0][1] == G[n-2][n-1]){
    cout << 1 << "\n";
    cout << "1 2" << "\n";
    cout << flush;
  }else if (G[0][1] == G[1][0] && G[0][1] != G[n-1][n-2] && G[0][1] == G[n-2][n-1]){
    cout << 1 << "\n";
    cout << n - 1 << " " << n << "\n";
    cout << flush;
  }else if (G[0][1] != G[1][0] && G[0][1] != G[n-1][n-2] && G[0][1] == G[n-2][n-1]){
    cout << 2 << "\n";
    cout << 2 << " " << 1 << "\n";
    cout << n - 1 << " " << n << "\n";
    cout << flush;
  }else if (G[0][1] == G[1][0] && G[0][1] == G[n-1][n-2] && G[0][1] != G[n-2][n-1]){
    cout << 1 << "\n";
    cout << n << " " << n - 1 << "\n";
    cout << flush;
  }else if (G[0][1] != G[1][0] && G[0][1] == G[n-1][n-2] && G[0][1] != G[n-2][n-1]){
    cout << 2 << "\n";
    cout << 2 << " " << 1 << "\n";
    cout << n << " " << n - 1 << "\n";
    cout << flush;
  }else if (G[0][1] == G[1][0] && G[0][1] != G[n-1][n-2] && G[0][1] != G[n-2][n-1]){
    cout << 0 << "\n";
    cout << flush;
  }else if (G[0][1] != G[1][0] && G[0][1] != G[n-1][n-2] && G[0][1] != G[n-2][n-1]){
    cout << 1 << "\n";
    cout << "2 1" << "\n";
    cout << flush;

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
  return 0;
}
